#include "fm_synth.h"

#define SAMPLERATE 44100

FM_synth::FM_synth() : Synth(){
}

FM_synth::~FM_synth(){
}

void FM_synth::initialize(std::string waveformCarrier, std::string waveformModulator, int midiPitch,float ratio, float mod_index){
    this->ratio = ratio; 
    this->mod_index = mod_index;

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
    // i put mod_index as amplitude for the modulair wave
    modulator->initialize(mod_index,SAMPLERATE);
    setMidiPitch(midiPitch);

}

void FM_synth::setRatio(float ratio){
    this->ratio = ratio;
    modulator->setFrequency(ratio * mtof(midiPitch));
}

float FM_synth::getRatio(){
    return ratio;
}

void FM_synth::updateOscFreq(float freq){
    // update frequency of modulator and carrier
    float modFrequency = freq * ratio;
    modulator->setFrequency(modFrequency);
    carrierFreq = freq;
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

void FM_synth::write_waveform(){   
    WriteToFile file("_waveForm.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {
        carrier->setFrequency(modulator->getSample() + carrier->getFrequency());
        samp = carrier->getSample();
        file.write(std::to_string(samp) + "\n");
        carrier->tick();
        modulator->tick();
    }
}
