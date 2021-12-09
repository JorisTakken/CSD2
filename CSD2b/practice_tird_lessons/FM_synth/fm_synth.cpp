#include <iostream>
#include "fm_synth.h"

#define SAMPLERATE 44100

FM_synth::FM_synth(float carrierFreq , float modulatorFreq) : modulatorFreq(modulatorFreq), carrierFreq(carrierFreq){
}

FM_synth::~FM_synth(){
}

void FM_synth::make_wave(){
    Sine modulator("sine",modulatorFreq, 0.2, SAMPLERATE);
    Saw carrier("saw",carrierFreq, 0.2, SAMPLERATE);

    float outBuf[44100];

    for(int i = 0; i < SAMPLERATE; i++) {
    float car_and_mod = carrier.getSample() * modulator.getSample();
    outBuf[i] = car_and_mod;
    modulator.tick();
    carrier.tick();
    }


    // for(int i = 0; i < SAMPLERATE; i++) {
    // std::cout << "buffer" << outBuf[i] << "\n";
    // }
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