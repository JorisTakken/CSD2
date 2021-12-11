#include <iostream>


#pragma once

class Oscillator{
    public:
        Oscillator(float frequency, float amplitude, int samplerate);
        ~Oscillator();
        void initialize(double freq, double amp, double samplerate);

        
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