#include <iostream>
#include "ring_mod_synth.h"

#define SAMPLERATE 44100

RING_synth::RING_synth(

    std::string waveCarrier,
    float carrierFreq,
    std::string waveModulator,
    float modulatorFreq,
    float amplitude) 
    : 
    Synth(waveCarrier, carrierFreq, waveModulator, modulatorFreq, amplitude){
}

RING_synth::~RING_synth(){
}

float RING_synth::calculate(){
    initialize();
    tick();
    sample = carrier->getSample() * modulator->getSample() * 0.5;
}
float Synth::getSample(){   
    return sample;
}

void RING_synth::write_waveform(){   
    WriteToFile file("1_fm_waveForm.csv", true);
    initialize();
    for(int i = 0; i < SAMPLERATE; i++) {
        car_and_mod = carrier->getSample() * modulator->getSample() * 0.5;
        file.write(std::to_string(car_and_mod) + "\n");
        tick();
    }
}

