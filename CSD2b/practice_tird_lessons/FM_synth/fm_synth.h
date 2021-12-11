#include <iostream>
#include "sine.h"
#include "saw.h"
#include "writeToFile.h"
#pragma once

class FM_synth{
    public:
        FM_synth(float carrierFreq , float modulatorFreq, float amplitude);
        ~FM_synth();

        
        void make_waveform();
        void make_fm_wave();
        void sound();
        void write_fm_waveform();
        


    protected:
        float modulatorFreq;
        float carrierFreq;
        float amplitude;
        float car_and_mod;

        Saw carrier;
        Sine modulator;
};

