#include <iostream>
#include "oscillator.h"

#pragma once

#define SAMPLERATE 44100

class Square : public Oscillator{
public:
    Square();
    Square(float frequency,float amplitude,int samplerate);
    ~Square();

protected:
    void calculate() override;
};