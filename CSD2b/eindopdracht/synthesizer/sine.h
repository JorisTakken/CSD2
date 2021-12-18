#include <iostream>
#include "oscillator.h"

#pragma once

#define SAMPLERATE 44100

class Sine : public Oscillator{
public:
    Sine();
    ~Sine();

protected:
    void calculate() override;
};