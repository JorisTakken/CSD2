#include "tremolo.h"


Tremolo::Tremolo(std::string waveform, float modFreq) : Effect(samplerate){
    if (waveform == "sine") {
        oscillator = new Sine(modFreq, samplerate);
    }
    else if (waveform == "saw") {
        oscillator = new Saw(modFreq, samplerate);
    }
    else if (waveform == "square") {
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

void Tremolo::processEffect(float &input, float &output){
    // modSignal = range 0 - 1 ==== oscillator in range van -1 tot 1 
    output = input * (oscillator->genNextSample() + 1.0) * 0.5;
}