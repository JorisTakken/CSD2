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

void FM_synth::calculate(){
    tick();
    sample = (pow(1.1,modulator->getSample() + carrier->getSample())) - 1;
    sample *= amplitude;
}

void FM_synth::write_waveform(){   
    WriteToFile file("1_fm_waveForm.csv", true);
    initialize();
    for(int i = 0; i < SAMPLERATE; i++) {
        car_and_mod = (pow(1.5,carrier->getSample() * modulator->getSample())) - 1;
        file.write(std::to_string(car_and_mod) + "\n");
        tick();
    }
}

