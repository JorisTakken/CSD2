#include "fm_synth.h"

#define SAMPLERATE 44100

FM_synth::FM_synth() : Synth(){
}

FM_synth::~FM_synth(){
    // when you make new oscillators, make sure to delete them after
    delete carrier;
    carrier = nullptr;

    delete modulator;
    modulator = nullptr;
}

void FM_synth::initialize(std::string waveformCarrier, std::string waveformModulator, int midiPitch,float ratio, float modDepth){
    this->ratio = ratio; 
    this->modDepth = modDepth;
    
    //------------------------------------------------------------------
    // the oscillator type is chosen here using waveformCarrier.
    // there are three choises for 2 oscillators Square, Sine and Saw
    //------------------------------------------------------------------
    if (waveformCarrier == "sine"){
        carrier = new Sine;
    }
    else if (waveformCarrier == "saw"){
        carrier = new Saw;
    }
    else if (waveformCarrier == "square"){
        carrier = new Square;
    }
    if (waveformModulator == "sine"){
        modulator = new Sine;
    }
    else if (waveformModulator == "saw"){
        modulator = new Saw;
    }
    else if (waveformModulator == "square"){
        modulator = new Square;
    }
    
    // initialize modulator and carrier with amplitude and samplerate
    // modDepth is the amplitude of the modulator
    carrier->initialize(1,SAMPLERATE);
    modulator->initialize(modDepth,SAMPLERATE);

    // modular frequency is the ratio multiplied by the base frequency
    // this calculation happens in setMidiPitch(Synth class) -> updateOscFreq(FM_synth class)
    setMidiPitch(midiPitch,0);
}

// by setting ratio, you immidiatly set frequency of modulator
void FM_synth::setRatio(float ratio){
    this->ratio = ratio;
    modulator->setFrequency(ratio * mtof(modFrequency));
}

float FM_synth::getRatio(){
    return ratio;
}

void FM_synth::updateOscFreq(int pitch,int oscillator_number){
    // update frequency of modulator and carrier
    float modFrequency = pitch * ratio;
    modulator->setFrequency(modFrequency);

    carrierFreq = pitch;
    carrier->setFrequency(carrierFreq);
}

float FM_synth::getFrequency(){
    return carrierFreq;
}

float FM_synth::nextSample(){   
    //------------------------------------------------------------------
    // this calculation goes to the input of the write to file and jack audio
    //------------------------------------------------------------------
    sample = carrier->getSample();
    modulator->tick();
    carrier->setFrequency(modulator->getSample() + carrierFreq);
    carrier->tick();

    return sample;
}

