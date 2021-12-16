#include <iostream>
#include "synthesizer.h"


Synth::Synth(
    std::string wave_1,
    float waveFreq_1,
    std::string wave_2,
    float waveFreq_2,
    float amplitude,
    float ratio) 
    : 
    wave_1(wave_1), 
    waveFreq_1(waveFreq_1),
    wave_2(wave_2), 
    waveFreq_2(waveFreq_2),
    amplitude(amplitude),
    ratio(ratio){
}

Synth::~Synth(){
    delete modulator; 
    modulator = nullptr;
    delete carrier; 
    carrier = nullptr;
}

void Synth::initialize(){
    if (wave_1 == "sineC"){
        carrier = new Sine();
    }
    else if (wave_1 == "sawC"){
        carrier = new Saw();
    }
    else if (wave_1 == "squareC"){
        carrier = new Square();

    }
    if (wave_2  == "sineM"){
        modulator = new Sine();;
    }
    else if (wave_2 == "sawM"){
        modulator = new Saw();
    }
    else if (wave_2 == "squareM"){
        modulator = new Square();
    }
    modulator->initialize(waveFreq_1,amplitude,SAMPLERATE);
    carrier->initialize(waveFreq_2,amplitude,SAMPLERATE);
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