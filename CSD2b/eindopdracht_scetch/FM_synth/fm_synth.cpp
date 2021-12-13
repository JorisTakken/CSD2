#include <iostream>
#include "fm_synth.h"

#define SAMPLERATE 44100

FM_synth::FM_synth(

    std::string waveCarrier,
    float carrierFreq,
    std::string waveModulator,
    float modulatorFreq,
    float amplitude) 
    : 
    Synth(waveCarrier, carrierFreq, waveModulator, modulatorFreq, amplitude){
}

FM_synth::~FM_synth(){
}

float FM_synth::calculate(){
    initialize();
    tick();
    sample = (pow(1.1,carrier->getSample() * modulator->getSample() * 0.5)) - 1;
}

float Synth::getSample(){   
    return sample;
}


void FM_synth::write_waveform(){   
    WriteToFile file("1_fm_waveForm.csv", true);
    initialize();
    for(int i = 0; i < SAMPLERATE; i++) {
        car_and_mod = (pow(1.1,carrier->getSample() * modulator->getSample() * 0.5)) - 1;
        file.write(std::to_string(car_and_mod) + "\n");
        tick();
    }
}

