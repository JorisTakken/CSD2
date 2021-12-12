#include <iostream>


#pragma once

class Oscillator{
    public:
        Oscillator(float frequency, float amplitude, int samplerate);
        ~Oscillator();

        float setFrequency(float frequency);
        float getFrequency();


        void initialize(double freq, double amp, double samplerate);

        
        void tick(); 
        float getSample();



    protected:
        virtual void calculate() = 0;
        float freq;

        float frequency;
        float amplitude;
        int samplerate;

        double sample;
        float phase;
};