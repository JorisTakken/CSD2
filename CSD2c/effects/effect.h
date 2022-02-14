#pragma once 
#include "sine.h"
#include "square.h"
#include "saw.h"

#include <iostream>

class Effect{
    public: 
        // dry -1 keer waarde
        // wet waarde
        Effect(unsigned int samplerate, float dryWet);
        ~Effect();
        virtual float process(float inputSample) = 0;

    protected: 
        Oscillator* oscillator;
        float modSignal;
        float inputSample;
        int samplerate = 44100;
        float dryWet;
        
};