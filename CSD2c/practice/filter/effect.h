#pragma once 
#include "sine.h"
#include "square.h"
#include "saw.h"

#include <iostream>

class Effect{
    public: 
        Effect(unsigned int samplerate);
        virtual ~Effect();


        void setDrywet(float newDryWet);
        float getDrywet();

        void applyDryWet(float &input, float &output);
        int msToSamps(float miliseconds);
        

    protected: 
        int samplerate = 44100;
        virtual void processEffect(float &input, float &output) = 0;
        Oscillator* oscillator;
    
    private:
        float dryWet = 1;


        
};