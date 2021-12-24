#include <iostream>


#pragma once

class Oscillator{
    public:
        Oscillator();
        virtual ~Oscillator();
        
        // initialisation for oscillators, amplitude and samplerate
        // FM_synth uses amplitude for ModDepth 
        void initialize(double amp, double samplerate);

        void setFrequency(float newFreq);
        float getFrequency();

        // tick function for calculating next sample of waveform.
        void tick();

        // get sample of calculated sample.
        float getSample();

    protected:
        // calcualate is in every oscillator differrent, thats why its a virtual funcion
        virtual void calculate() = 0;

        float frequency;
        float amplitude;
        int samplerate;

        double sample;
        float phase;
};