#include <iostream>
#include "fm_synth.h"

#define SAMPLERATE 44100

FM_synth::FM_synth(float carrierFreq , float modulatorFreq,float amplitude) : 
    modulatorFreq(modulatorFreq), carrierFreq(carrierFreq),amplitude(amplitude){
}

FM_synth::~FM_synth(){
}

void FM_synth::make_waveform() {
    Sine modulator("sine",modulatorFreq, amplitude, SAMPLERATE);
    Saw carrier("saw",carrierFreq, amplitude, SAMPLERATE);


}

void FM_synth::make_fm_wave(){
    make_waveform();
    float outBuf[44100];
    for(int i = 0; i < SAMPLERATE; i++) {
    float car_and_mod = carrier.getSample() * modulator.getSample();
    outBuf[i] = car_and_mod;
    modulator.tick();
    carrier.tick();
    }
}


void FM_synth::sound(){
    make_waveform();
    make_fm_wave();
}


void FM_synth::write_fm_waveform(){
    make_waveform();
    
    WriteToFile file("1_fm_waveForm.csv", true);
    make_fm_wave();
    file.write(std::to_string(car_and_mod) + "\n");
}