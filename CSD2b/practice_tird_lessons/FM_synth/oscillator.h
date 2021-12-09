#include <iostream>


#pragma once

class Oscillator{
    public:
        Oscillator(std::string waveform,float frequency, float amplitude, int samplerate);
        ~Oscillator();

        

    protected:
        float frequency;
        float amplitude;
        int samplerate;
        std::string waveform;
};