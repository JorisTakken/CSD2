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
    waveCarrier(waveCarrier), 
    carrierFreq(carrierFreq),
    waveModulator(waveModulator), 
    modulatorFreq(modulatorFreq),
    amplitude(amplitude){

}

FM_synth::~FM_synth(){
}

void FM_synth::choose_waveform(){
    if (waveCarrier == "sine"){
        carrier = sineC;
    }
    else if (waveCarrier == "saw"){
        carrier = sawC;
    }

    if (waveModulator  == "sine"){
        modulator = sineM;
    }
    else if (waveModulator == "saw"){
        modulator = sawM;
    }
    modulator->initialize(carrierFreq,amplitude,SAMPLERATE);
    carrier->initialize(modulatorFreq,amplitude,SAMPLERATE);
}


// float FM_synth::calculate_fm(){
//     car_and_mod = carrier->getSample() + modulator->getSample() / 2;
//     modulator->tick();
//     carrier->tick();
// }



void FM_synth::make_fm_wave(){
    choose_waveform();
    float outBuf[44100];
    for(int i = 0; i < SAMPLERATE; i++) {
        //calculate_fm();
        car_and_mod = carrier->getSample() + modulator->getSample() / 2;
        outBuf[i] = car_and_mod;
        modulator->tick();
        carrier->tick();
    }
}


void FM_synth::sound(){
    make_fm_wave();
}


void FM_synth::write_fm_waveform(){   
    WriteToFile file("1_fm_waveForm.csv", true);
    choose_waveform();

    for(int i = 0; i < SAMPLERATE; i++) {
        car_and_mod = carrier->getSample() + modulator->getSample() / 2;
        file.write(std::to_string(car_and_mod) + "\n");
        modulator->tick();
        carrier->tick();
    }
}