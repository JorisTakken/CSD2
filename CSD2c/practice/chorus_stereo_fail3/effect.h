#pragma once 
#include "sine.h"
#include "square.h"
#include "saw.h"

#include <iostream>

class Effect{
    public: 
        Effect(unsigned int samplerate = 44100);
        virtual ~Effect();

        // to apply effect
        virtual float processEffect(float input) = 0;

        
        void setDrywet(float newDryWet);
        float getDrywet();
    protected: 
        // to apply dry wet function
        float applyDryWet(float input);


        Oscillator* oscillator;
        int samplerate = 44100;
    
    private:
        
        float dryWet = 1;


        
};