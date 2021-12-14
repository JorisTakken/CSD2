#include <iostream>


#pragma once

class Oscillator{
    public:
        Oscillator(float frequency, float amplitude, int samplerate);
        virtual ~Oscillator();
        void initialize(double freq, double amp, double samplerate);


        float setFrequency(float newFreq);
        float getFrequency();

        
        void tick(); 
        float getSample();

    protected:
        virtual void calculate() = 0;

        float frequency;
        float amplitude;
        int samplerate;
        
        float newFreq;

        double sample;
        float phase;
};