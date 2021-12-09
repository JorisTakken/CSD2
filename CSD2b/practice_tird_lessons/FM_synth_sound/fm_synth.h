#include <iostream>
#include "sine.h"
#include "saw.h"
#include "writeToFile.h"
#pragma once

class FM_synth{
    public:
        FM_synth(float carrierFreq , float modulatorFreq,float samplerate);
        ~FM_synth();

        float make_wave();
        void get_wave();
        void write_wave();


    protected:
        float modulatorFreq;
        float carrierFreq;
        float samplerate;
};

