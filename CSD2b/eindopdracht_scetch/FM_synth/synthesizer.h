#include <iostream>
#include "sine.h"
#include "saw.h"
#include "square.h"

#include "math.h"
#include "writeToFile.h"

#pragma once

class Synth{
    public:
        Synth(
            std::string waveCarrier,
            float carrierFreq,
            std::string waveModulator,
            float modulatorFreq,
            float amplitude
        );

        virtual ~Synth();

        float setFrequency_carrier(float newFreq);       
        float getFrequency_carrier();        

        void initialize();

        void tick();
        float getSample();        

    protected:
        virtual void calculate() = 0;

        std::string waveCarrier;
        float carrierFreq;
        std::string waveModulator;
        float modulatorFreq;
        float amplitude;
        float sample;

        float freqModulator;
        // float newFreq;
        // float newfrequency;

        Oscillator* modulator; 
        Oscillator* carrier;

        // Sine* sineM = new Sine();
        // Sine* sineC = new Sine();
        // Saw* sawM = new Saw();
        // Saw* sawC = new Saw();
        // Square* squareM = new Square();
        // Square* squareC = new Square();
};