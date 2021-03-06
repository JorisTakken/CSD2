#include <iostream>
#include "synthesizer.h"

#pragma once

class FM_synth : public Synth{
    public:
        FM_synth(
        std::string waveCarrier,
        float carrierFreq ,
        std::string waveModulator,
        float modulatorFreq,
        float amplitude);

        ~FM_synth();
        
        void write_waveform();
        void calculate() override;  

        
    protected:
        float car_and_mod;

        
};

