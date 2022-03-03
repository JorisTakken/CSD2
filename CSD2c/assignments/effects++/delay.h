#pragma once 
#include "effect.h"
#include <iostream>

class Delay : public Effect{
    public:
        Delay(int size, int delayTime, float feedback);
        ~Delay() override;

        void processEffect(float &input, float &output) override;
        float getDistance();

    protected: 
        int size;
        int numSamplesDelay;
        float feedback;

        float* buffer;
        
        int writePoint;
        int readPoint;

    private:
        inline float wrap(int point);

};

