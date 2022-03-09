#pragma once 
#include "effect.h"
#include <iostream>

class Delay : public Effect{
    public:
        Delay(int size, int delayTime, float feedback);
        ~Delay();



        void setDelaytime(float newDelaytime);

        float map(float input, int x1, int x2 , float min, float max);

        float wrap(int point);

        
    protected: 
        virtual void applyEffect(float& input, float& output);


        int size;
        int numSamplesDelay;
        float feedback;

        int readNext = 0;

        float* buffer;
        
        int writePoint;
        int readPoint;

    private:

};

