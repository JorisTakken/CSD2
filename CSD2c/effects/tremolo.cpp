#include "tremolo.h"


Tremolo::Tremolo(std::string waveform, float modFreq) : Effect(samplerate){
    if (waveform == "sine") {
        oscillator = new Sine(modFreq, samplerate);
    }
    if (waveform == "saw") {
        oscillator = new Saw(modFreq, samplerate);
    }
    if (waveform == "square") {
        oscillator = new Square(modFreq, samplerate);
    }
}

Tremolo::~Tremolo(){
    delete oscillator;
    oscillator = nullptr;
}

void Tremolo::setModFreq(float freq){
    oscillator->setFrequency(freq);
}

float Tremolo::process(float inputSample){
    // modSignal = range 0 - 1 ==== oscillator in range van -1 tot 1 
    modSignal = (oscillator->genNextSample() + 1.0) * 0.5;
    modSignal *= dryWet;
    modSignal += 1.0 - dryWet;

    modSignal *= inputSample;
    return modSignal;
}