#pragma once 
#include "effect.h"
#include <iostream>

class modDelay : public Effect{
    public:
        modDelay(int size,int samplesDelay,float modDelayRate);
        ~modDelay() override;

        float processEffect(float input) override;

        int msToSamps(float miliseconds);


    protected: 
        float* modDelayBuffer;

        int size = samplerate;
        
        float modDelayRate;
        int samplesDelay;

        int writePoint;
        int readPoint;

        
    private:
        inline float wrap(int point);
        int inRange(float input, float x1, float x2 , int min, int max);


};

