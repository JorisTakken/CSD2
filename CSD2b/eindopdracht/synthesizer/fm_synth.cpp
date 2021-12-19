#include "fm_synth.h"

#define SAMPLERATE 44100

FM_synth::FM_synth(){
}

FM_synth::~FM_synth(){
}



void FM_synth::initialize(std::string waveform,float frequency,float ratio, float mod_index
){
    carrier = new Sine;
    modulator = new Sine;
    this->frequency = frequency;
    carrier->initialize(frequency,1,SAMPLERATE);
    modulator->initialize(frequency,mod_index,SAMPLERATE);

    modFrequency = frequency * ratio;
    modulator->setFrequency(modFrequency);
}

void FM_synth::setFrequency(float newFreq){
    this->frequency = newFreq;
    carrier->setFrequency(newFreq);
}

float FM_synth::getFrequency(){
    freq = carrier->getFrequency();
    return freq;
}









float FM_synth::sound(){   
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