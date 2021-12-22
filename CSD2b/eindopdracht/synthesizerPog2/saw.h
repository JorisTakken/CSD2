#include <iostream>
#include "oscillator.h"

#pragma once

#define SAMPLERATE 44100

class Saw : public Oscillator{
public:
    Saw();
    ~Saw();

protected:
    void calculate() override;
};