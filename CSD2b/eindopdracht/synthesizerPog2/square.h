#include <iostream>
#include "oscillator.h"

#pragma once

#define SAMPLERATE 44100

class Square : public Oscillator{
public:
    Square();
    ~Square();

protected:
    void calculate() override;
};