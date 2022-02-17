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
        virtual ~Effect();

        void process(float &input, float &output);

        void setDrywet(float newDryWet,float min ,float max);
        float getDrywet();

        // float liniairInterlopation(float input, float min, float max);

    protected: 
        virtual void processEffect(float &input, float &output) = 0;

        Oscillator* oscillator;
        int samplerate = 44100;
        float dryWet = 1;
    
    private:
        float inputSample;

        
};