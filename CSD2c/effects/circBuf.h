#pragma once 
#include "effect.h"
#include <iostream>

class circBuf : public Effect{
    public:
        circBuf(int size, int numSamplesDelay);
        ~circBuf();

        void addValue(float newValue);
        float readValue();
        
        float wrap(int point);

        float getDistance();

    protected: 
        int size;
        int numSamplesDelay;

        float* buffer;
        
        int writePoint;
        int readPoint;

};

