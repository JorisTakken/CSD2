#pragma once 
#include "effect.h"
#include <iostream>

class Chorus : public Effect{
    public:
        Chorus(int size,int samplesDelay,float chorusRate);
        ~Chorus() override;

        void processEffect(float &input, float &output) override;

    protected: 
        float* chorusBuffer;

        int size = samplerate;
        
        float chorusRate;
        int samplesDelay;

        int writePoint;
        int readPoint;

        
    private:
        inline float wrap(int point);
        float inRange(float input, int x1, int x2 , float min, float max);


};

