#pragma once 
#include "effect.h"
#include <iostream>

class Chorus : public Effect{
    public:
        Chorus(int size,int samplesDelay,float chorusRate);
        ~Chorus() override;

        float processEffect(float input) override;

    protected: 
        float* chorusBuffer;

        int size = samplerate;
        
        float chorusRate;
        int samplesDelay;

        int writePoint;
        int readPoint;

        
    private:
        inline float wrap(int point);
        int inRange(float input, float x1, float x2 , int min, int max);


};

