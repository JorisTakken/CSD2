#include "fm_synth.h"

#define SAMPLERATE 44100

FM_synth::FM_synth() : Synth(){
}

FM_synth::~FM_synth(){
    delete carrier;
    carrier = nullptr;

    delete modulator;
    modulator = nullptr;
}

void FM_synth::initialize(std::string waveformCarrier, std::string waveformModulator, int midiPitch,float ratio, float modDepth){
    this->ratio = ratio; 
    this->modDepth = modDepth;

    std::cout << waveformCarrier << waveformModulator << std::endl;

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
    
    carrier->initialize(1,SAMPLERATE);
    
    // modular frequency is the ratio multiplied by the base frequency
    // i put modDepth as amplitude for the modulair wave
    modulator->initialize(modDepth,SAMPLERATE);
    setMidiPitch(midiPitch,0);

}

void FM_synth::setRatio(float ratio){
    this->ratio = ratio;
    modulator->setFrequency(ratio * mtof(midiPitch));
}

float FM_synth::getRatio(){
    return ratio;
}

void FM_synth::updateOscFreq(int pitch,int oscillator_number){
    // update frequency of modulator and carrier
    float modFrequency = pitch * ratio;
    modulator->setFrequency(modFrequency);
    carrierFreq = pitch;
    carrier->setFrequency(carrierFreq + modulator->getSample());
}

float FM_synth::getFrequency(){
    return carrierFreq;
}

float FM_synth::nextSample(){   
    sample = carrier->getSample();
    modulator->tick();
    carrier->setFrequency(modulator->getSample() + carrierFreq);
    carrier->tick();

    return sample;
}

