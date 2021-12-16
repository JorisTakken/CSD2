#include <iostream>
#include "synthesizer.h"

#pragma once

class Wavetable : public Synth{
    public:
        Wavetable(
        std::string wave_1,
        float waveFreq_1 ,
        std::string waveModulator,
        float modulatorFreq,
        float amplitude,
        float ratio);

        ~Wavetable();
        
        void write_waveform();
        void calculate() override;  

        
    protected:
        float car_and_mod;

        
};

