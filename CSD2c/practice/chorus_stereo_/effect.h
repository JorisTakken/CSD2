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
        virtual void processEffect(float &input, float &output) = 0;
        void applyDryWet(float &input, float &output);
        
        float msToSamps(float miliseconds);
        
        void setDrywet(float newDryWet);
        float getDrywet();
    protected: 
        // to apply effect

        Oscillator* oscillator;
        int samplerate = 44100;
    
    private:
        
        float dryWet = 1;


        
};