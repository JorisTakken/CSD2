#include <iostream>
#include "sine.h"
#include "saw.h"
#include "square.h"

#include "math.h"
#include "writeToFile.h"

#pragma once

class FM_synth{
    public:
        FM_synth(
        std::string waveCarrier,
        float carrierFreq ,
        std::string waveModulator,
        float modulatorFreq,
        float amplitude);

        ~FM_synth();
        
        void choose_waveform();
        void write_fm_waveform_synth1();
        void write_fm_waveform_synth2();

        void synth1_tick();
        void synth2_tick();

        float getSample();
        
    protected:

        std::string waveCarrier;
        float carrierFreq;
        std::string waveModulator;
        float modulatorFreq;
        float amplitude;

        float car_and_mod;
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

