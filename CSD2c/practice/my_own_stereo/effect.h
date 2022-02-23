#pragma once 
#include "sine.h"
#include "../../../../CSD_voorbelden/CSD_21-22/csd2c/sharedCode/square.h"
#include "../../../../CSD_voorbelden/CSD_21-22/csd2c/sharedCode/saw.h"

#include <iostream>

class Effect{
    public: 
        Effect(unsigned int samplerate);
        virtual ~Effect();

        // to apply dry wet function
        void process(float &input, float &output);
        
        void setDrywet(float newDryWet);
        float getDrywet();
    protected: 
        // to apply effect
        virtual void processEffect(float &input, float &output) = 0;

        Oscillator* oscillator;
        int samplerate = 44100;
    
    private:
        
        float dryWet = 1;


        
};