#pragma once 

#include <iostream>

class Delay{
    public:
        Delay(int size, int numSamplesDelay);
        ~Delay();

        // PROCESS FUNTION IN STEAD OF ADD AND READ

        float processEffect(float inputSample);
        float process(float sample);

        float getDistance();

    protected: 
        int size;
        int numSamplesDelay;

        float* buffer;
        
        int writePoint;
        int readPoint;

    private:
        inline float wrap(int point);

};

