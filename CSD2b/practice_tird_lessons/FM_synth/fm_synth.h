#include <iostream>
#include "sine.h"
#include "saw.h"
#include "writeToFile.h"
#pragma once

class FM_synth{
    public:
        FM_synth(float carrierFreq , float modulatorFreq);
        ~FM_synth();

        void make_wave();
        void write_wave();


    protected:
        float modulatorFreq;
        float carrierFreq;
      
};

