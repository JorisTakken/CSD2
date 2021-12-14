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
            char waveCarrier,
            float carrierFreq,
            char waveModulator,
            float modulatorFreq,
            float amplitude
        );
        ~Synth();
        void initialize();

        void tick();
        float getSample();        

    protected:
        virtual void calculate() = 0;

        char waveCarrier;
        float carrierFreq;
        char waveModulator;
        float modulatorFreq;
        float amplitude;
        float sample;

        Oscillator* modulator; 
        Oscillator* carrier;

        Sine* sineM = new Sine();
        Sine* sineC = new Sine();
        Saw* sawM = new Saw();
        Saw* sawC = new Saw();
        Square* squareM = new Square();
        Square* squareC = new Square();
};