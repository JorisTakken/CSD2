#pragma once 
#include "effect.h"
#include <iostream>

class circBuf : public Effect{
    public:
        circBuf(int size, int numSamplesDelay);
        ~circBuf();

        // PROCESS FUNTION IN STEAD OF ADD AND READ
        float process(float inputSample) override;

        float wrap(int point);
        float getDistance();

    protected: 
        int size;
        int numSamplesDelay;

        float* buffer;
        
        int writePoint;
        int readPoint;

};

