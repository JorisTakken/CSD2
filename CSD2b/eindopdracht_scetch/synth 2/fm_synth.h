#include <iostream>
#include "synthesizer.h"


#pragma once

class FM_synth : public Synth{
    public:
        FM_synth(
            std::string wave_1,
            float freqWave_1,
            std::string wave_2,
            float freqWave_2,
            float amplitude);

        ~FM_synth();
        
        void initialize();
        void write_waveform();
        void calculate() override;  

        
    protected:
        float wave;

        Oscillator* modulator; 
        Oscillator* carrier;

        
};

