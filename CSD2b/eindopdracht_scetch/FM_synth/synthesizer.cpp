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
    delete modulator; 
    modulator = nullptr;
    delete carrier; 
    carrier = nullptr;
}

void Synth::initialize(){
    if (waveCarrier == "sineC"){
        carrier = new Sine();
    }
    else if (waveCarrier == "sawC"){
        carrier = new Saw();
    }
    else if (waveCarrier == "squareC"){
        carrier = new Square();

    }
    if (waveModulator  == "sineM"){
        modulator = new Sine();;
    }
    else if (waveModulator == "sawM"){
        modulator = new Saw();
    }
    else if (waveModulator == "squareM"){
        modulator = new Square();
    }
    modulator->initialize(carrierFreq,amplitude,SAMPLERATE);
    carrier->initialize(modulatorFreq,amplitude,SAMPLERATE);
}


float Synth::setFrequency_carrier(float newFreqCar){
    // newfrequency = newFreq;
    modulator->setFrequency(newFreqCar);
    std::cout << "frequency" << freqModulator << std::endl;
}
        
float Synth::getFrequency_carrier(){
    // freqModulator = ;
    
    return modulator->getFrequency(); 
}

void Synth::tick(){  
    modulator->tick();
    carrier->tick();
}

float Synth::getSample(){   
    // sample *= amplitude;
    return sample;
}