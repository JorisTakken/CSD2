#include <iostream>
#include "oscillator.h"

#pragma once

#define SAMPLERATE 44100

class Saw : public Oscillator{
public:
    Saw(std::string waveform,float frequency,float amplitude,int samplerate);
    ~Saw();
    // void setFrequency(float frequency);
    // void setAmplitude(float amplitude);
    // float getFrequency();
    // float getAmplitude();

    void calculate(float phase);


protected:
    float frequency;
    float amplitude;
    int samplerate;
    std::string waveform;

    float sample;
    float phase;

};