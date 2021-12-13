#include <iostream>
#include "sine.h"
#include "saw.h"
#include "square.h"


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
        ~Synth();
        void initialize();

        void tick();
        float getSample();
        virtual float calculate();
        

    protected:
        std::string waveCarrier;
        float carrierFreq;
        std::string waveModulator;
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