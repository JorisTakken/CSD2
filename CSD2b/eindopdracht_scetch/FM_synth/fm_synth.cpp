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
    else if (waveCarrier == "square"){
        carrier = squareC;
    }
    if (waveModulator  == "sine"){
        modulator = sineM;
    }
    else if (waveModulator == "saw"){
        modulator = sawM;
    }
    else if (waveModulator == "square"){
        modulator = squareM;
    }
    modulator->initialize(carrierFreq,amplitude,SAMPLERATE);
    carrier->initialize(modulatorFreq,amplitude,SAMPLERATE);
}



void FM_synth::synth1_tick(){   
    choose_waveform();
        modulator->tick();
        carrier->tick();
        sample = carrier->getSample() * modulator->getSample() * 0.5;
        sample *= amplitude;
}

void FM_synth::synth2_tick(){   
    choose_waveform();
        modulator->tick();
        carrier->tick();
        sample = (pow(1.1,modulator->getSample() + carrier->getSample())) - 1;
        sample *= amplitude;
}

float FM_synth::getSample(){   
    return sample;
}

void FM_synth::write_fm_waveform_synth1(){   
    WriteToFile file("1_fm_waveForm.csv", true);
    choose_waveform();
    for(int i = 0; i < SAMPLERATE; i++) {
        car_and_mod = carrier->getSample() * modulator->getSample() * 0.5;
        file.write(std::to_string(car_and_mod) + "\n");
        modulator->tick();
        carrier->tick();
    }
}

void FM_synth::write_fm_waveform_synth2(){   
    WriteToFile file("1_fm_waveForm.csv", true);
    choose_waveform();
    for(int i = 0; i < SAMPLERATE; i++) {
        car_and_mod = (pow(1.1,modulator->getSample() + carrier->getSample())) - 1;
        file.write(std::to_string(car_and_mod) + "\n");
        modulator->tick();
        carrier->tick();
    }
}

