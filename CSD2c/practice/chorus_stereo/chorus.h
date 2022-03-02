#pragma once 
#include "effect.h"
#include <iostream>

class Chorus : public Effect{
    public:
        Chorus(int delayMS ,float chorusRate, float chorusDepth);
        ~Chorus() override;

        float processEffect(float input) override;

        int msToSamps(float miliseconds);


    protected: 
        float* chorusBuffer;

        int delayMS;
        float chorusRate;
        float chorusDepth;
        
        int writePoint;
        int readPoint;
    private:
        inline float wrap(int point);
        int inRange(float input, float x1, float x2 , int min, int max);


};

