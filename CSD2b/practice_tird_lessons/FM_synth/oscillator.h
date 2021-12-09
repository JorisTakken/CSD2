#include <iostream>


#pragma once

class Oscillator{
    public:
        Oscillator(std::string waveform,float frequency, float amplitude, int samplerate);
        ~Oscillator();

        float getSample(float sample);
        float tick(); 
        

    protected:
        float frequency;
        float amplitude;
        int samplerate;
        std::string waveform;

        float sample;
        float phase;
};