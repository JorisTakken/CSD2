#pragma once 
#include "effect.h"
#include <iostream>

class Delay : public Effect{
    public:
        Delay(int size, int delayTime, float feedback);
        ~Delay() override;

        virtual void processEffect(float &input, float &output) = 0;
        float getDistance();

        int size;
        int numSamplesDelay;
        float* buffer;
        int writePoint;
        int readPoint;

    protected: 
        float feedback;
        inline float wrap(int point);


    private:

};

