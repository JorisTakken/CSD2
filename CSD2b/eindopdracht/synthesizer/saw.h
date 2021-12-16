#include <iostream>
#include "oscillator.h"

#pragma once

#define SAMPLERATE 44100

class Saw : public Oscillator{
public:
    Saw(); 
    Saw(float frequency,float amplitude,int samplerate);
    ~Saw();
    // void setFrequency(float frequency);
    // void setAmplitude(float amplitude);
    // float getFrequency();
    // float getAmplitude();



protected:
    void calculate() override;
};