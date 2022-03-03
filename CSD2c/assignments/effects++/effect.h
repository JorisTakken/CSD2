#pragma once 
#include "sine.h"
#include "square.h"
#include "saw.h"

#include <iostream>

class Effect{
    public: 
        Effect(unsigned int samplerate);
        virtual ~Effect();

        // to apply dry wet function
        
        void setDrywet(float newDryWet);
        float getDrywet();
        void applyDryWet(float &input, float &output);

    protected: 
        int samplerate = 44100;
        virtual void processEffect(float &input, float &output) = 0;
        // to apply effect
        Oscillator* oscillator;
    
    private:
        
        float dryWet = 1;


        
};