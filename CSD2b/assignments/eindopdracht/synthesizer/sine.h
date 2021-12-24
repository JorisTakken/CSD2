#include <iostream>
#include "oscillator.h"

#pragma once

#define SAMPLERATE 44100

class Sine : public Oscillator{
public:
    Sine();
    ~Sine();

protected:
    // make a sine wave
    void calculate() override;
};