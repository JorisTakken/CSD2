#pragma once 
#include "sine.h"
#include "square.h"
#include "saw.h"

#include <iostream>

class Effect{
    public: 
        Effect(unsigned int samplerate = 44100);
        virtual ~Effect();

        // to apply dry wet function
        float process(float input);
        
        void setDrywet(float newDryWet);
        float getDrywet();
    protected: 
        // to apply effect
        virtual float processEffect(float input) = 0;

        Oscillator* oscillator;
        int samplerate = 44100;
    
    private:
        
        float dryWet = 1;


        
};