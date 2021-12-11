#include <iostream>
#include "sine.h"
#include "saw.h"
#include "math.h"
#include "writeToFile.h"
#pragma once

class FM_synth{
    public:
        FM_synth(std::string waveCarrier,float carrierFreq ,std::string waveModulator,float modulatorFreq,float amplitude);
        ~FM_synth();

        void choose_waveform();

        void make_fm_wave();
        void sound();

        void write_fm_waveform();
        
        // float calculate_fm();


    protected:
        std::string waveCarrier;
        float carrierFreq;
        std::string waveModulator;
        float modulatorFreq;
        float amplitude;
        float car_and_mod;

        Oscillator* modulator; 
        Oscillator* carrier;

        Sine* sineM = new Sine();
        Sine* sineC = new Sine();
        Saw* sawM = new Saw();
        Saw* sawC = new Saw();
};

