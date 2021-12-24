#include <iostream>
#include "oscillator.h"
#pragma once

#define SAMPLERATE 44100

class Sine : public Oscillator{
public:
    Sine(std::string waveform,float frequency, float amplitude, int samplerate);
    ~Sine();


    float getSample();
    virtual void tick();

    void list_of_values(std::string values_sine);

protected:
    float frequency;
    float amplitude;

    int samplerate;

    float sample;
    float phase;
    std::string waveform;
    std::string values_sine[100];
};