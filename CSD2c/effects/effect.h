#pragma once 
#include "sine.h"
#include "square.h"
#include "saw.h"

#include <iostream>

class Effect{
    public: 
        // dry -1 keer waarde
        // wet waarde
        Effect(unsigned int samplerate);
        ~Effect();

        virtual float process(float inputSample) = 0;
        
        void setDrywet(float newDryWet);

    protected: 
        Oscillator* oscillator;
        float modSignal;
        float inputSample;

        int samplerate = 44100;

        float dryWet = 1;
        
};