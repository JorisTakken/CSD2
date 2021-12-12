#include <iostream>
#include "fm_synth.h"

#define SAMPLERATE 44100

FM_synth::FM_synth(float carrierFreq , float modulatorFreq, float samplerate) : modulatorFreq(modulatorFreq), carrierFreq(carrierFreq),samplerate(samplerate){
}

FM_synth::~FM_synth(){
}

float FM_synth::make_wave(){
    Sine modulator("sine",modulatorFreq, 0.2, samplerate);
    Saw carrier("saw",carrierFreq, 0.2, samplerate);

    float outBuf[44100];

    for(int i = 0; i < SAMPLERATE; i++) {
    float car_and_mod = carrier.getSample() * modulator.getSample();
    outBuf[i] = car_and_mod;
    modulator.tick();
    carrier.tick();
    }

    for(int i = 0; i < SAMPLERATE; i++) {
        return outBuf[i];
    }
    

    // for(int i = 0; i < SAMPLERATE; i++) {
    // std::cout << "buffer" << outBuf[i] << "\n";
    // }
}

void FM_synth::get_wave(){
    
}


void FM_synth::write_wave(){
    Sine modulator("sine",modulatorFreq, 0.2, SAMPLERATE);
    Saw carrier("saw",carrierFreq, 0.2, SAMPLERATE);

    WriteToFile file("1_fm_waveForm.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {

    float car_and_mod = carrier.getSample() * modulator.getSample();

    file.write(std::to_string(car_and_mod) + "\n");
    carrier.tick();
    modulator.tick();
    }
}