#pragma once 
#include <iostream>

class Delay{
    public:
        Delay(int size, int delayTime, float feedback);
        ~Delay();

        float getDistance();

        float process(float input);
        float setDelaytime(float newDelaytime);

        float map(float input, int x1, int x2 , float min, float max);
        
    protected: 

        int size;
        int numSamplesDelay;
        float feedback;

        int readNext = 0;

        float* buffer;
        
        int writePoint;
        int readPoint;

    private:
        inline float wrap(int point);

};

