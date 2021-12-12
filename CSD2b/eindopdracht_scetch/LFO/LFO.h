#include <iostream>
#include "oscillator.h"

#pragma once

#define SAMPLERATE 44100

class Lfo : public Oscillator{
public:
    Lfo();  
    Lfo(float frequency, float amplitude, int samplerate);
    ~Lfo();

protected:
    void calculate() override;
};