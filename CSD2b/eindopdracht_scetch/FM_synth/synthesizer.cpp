#include <iostream>
#include "synthesizer.h"


Synth::Synth(
    char waveCarrier,
    float carrierFreq,
    char waveModulator,
    float modulatorFreq,
    float amplitude) 
    : 
    waveCarrier(waveCarrier), 
    carrierFreq(carrierFreq),
    waveModulator(waveModulator), 
    modulatorFreq(modulatorFreq),
    amplitude(amplitude){
}

Synth::~Synth(){
}

void Synth::initialize(){
    char squareC;
    char sineC;
    char sawC;

    char squareM;
    char sineM;
    char sawM;

    if (waveCarrier == sineC){
        carrier = sineC;
    }
    else if (waveCarrier == sawC){
        carrier = sawC;
    }
    else if (waveCarrier == squareC){
        carrier = squareC;
    }
    if (waveModulator  == sineM){
        modulator = sineM;
    }
    else if (waveModulator == sawM){
        modulator = sawM;
    }
    else if (waveModulator == squareM){
        modulator = squareM;
    }
    modulator->initialize(carrierFreq,amplitude,SAMPLERATE);
    carrier->initialize(modulatorFreq,amplitude,SAMPLERATE);
}

void Synth::tick(){  
    modulator->tick();
    carrier->tick();
}

float Synth::getSample(){   
    sample *= amplitude;
    return sample;
}