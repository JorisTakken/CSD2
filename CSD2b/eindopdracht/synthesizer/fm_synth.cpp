#include "fm_synth.h"

#define SAMPLERATE 44100

FM_synth::FM_synth() : Synth(){
}

FM_synth::~FM_synth(){
}

void FM_synth::initialize(std::string waveformCarrier, std::string waveformModulator, int midiPitch,float ratio, float mod_index){
    this->frequency = MTOF(midiPitch);
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
    
    carrier->initialize(frequency,1,SAMPLERATE);
    
    // modular frequency is the ratio multiplied by the base frequency
    // i put mod_index as amplitude for the modulair wave
    modFrequency = frequency * ratio;
    modulator->initialize(modFrequency,mod_index,SAMPLERATE);
}

void FM_synth::setPitch(int pitch){
    setMidiPitch(pitch);
    this->frequency = MTOF(getMidiPitch());
    carrier->setFrequency(MTOF(getMidiPitch()));
}

float FM_synth::getFrequency(){
    freq = carrier->getFrequency();
    return freq;
}

float FM_synth::nextSample(){   
    carrier->setFrequency(modulator->getSample() + carrier->getFrequency());
    sample = carrier->getSample();
    carrier->tick();
    modulator->tick();
    return sample;
}

void FM_synth::write_waveform(){   
    WriteToFile file("1_fm_waveForm.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {
        carrier->setFrequency(modulator->getSample() + carrier->getFrequency());
        samp = carrier->getSample();
        file.write(std::to_string(samp) + "\n");
        carrier->tick();
        modulator->tick();
    }
}


// // set at initialisation or when you want to alter the modulation
// carrier.setAmplitude(modDepth); 
// carrier.setFrequency(modFreq); 


// // update functionality
// carrier.setFreq(modulator.getSample() + carrierFreq); 
// sample = carrier.getSample(); 