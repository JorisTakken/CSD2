#pragma once 
#include "effect.h"
#include <iostream>

class Delay : public Effect{
    public:
        Delay(int size, int delayTime, float feedback);
        ~Delay() override;

        // void processEffect(float &input, float &output) override;
        float getDistance();
        void setDelaytime(int newDelayTime);
        float genNextSample(float inputSample);

        

    protected: 
        float feedback;
        int size;
        int numSamplesDelay;
        float* buffer;
        int writePoint;
        int readPoint;
        inline float wrap(int point);

        float outputSample;


    private:

};

