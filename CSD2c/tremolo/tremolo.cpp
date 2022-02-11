#include "tremolo.h"


Tremolo::Tremolo(std::string waveform, float modFreq, int samplerate) : modSignal(0){
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

float Tremolo::process(float sample){
    // modSignal = range 0 - 1
    // oscillator in range van -1 tot 1 
    // scale the sine to 0 - 1
    modSignal = (oscillator->genNextSample() + 1.0) * 0.5;
    return modSignal;
}