#include <iostream>


#pragma once

class Oscillator{
    public:
        Oscillator();
        virtual ~Oscillator();
        
        void initialize(double freq, double amp, double samplerate);

        void setFrequency(float newFreq);
        float getFrequency();

        void tick(); 
        float getSample();

    protected:
        virtual void calculate() = 0;

        float frequency;
        float amplitude;
        int samplerate;

        double sample;
        float phase;
};