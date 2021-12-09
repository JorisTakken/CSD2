#include <iostream>
#include "oscillator.h"

#pragma once

#define SAMPLERATE 44100

class Sine : public Oscillator{
public:
    Sine(std::string waveform,float frequency, float amplitude, int samplerate);
    ~Sine();

    void calculate(float phase);


protected:
    float frequency;
    float amplitude;

    int samplerate;

    float sample;
    float phase;
    std::string waveform;
  
};