#include <iostream>
#include "synthesizer.h"


Synth::Synth(
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

Synth::~Synth(){
}

void Synth::initialize(){
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

void Synth::tick(){  
    modulator->tick();
    carrier->tick();
    sample *= amplitude;
}

float Synth::getSample(){   
    return sample;
}

