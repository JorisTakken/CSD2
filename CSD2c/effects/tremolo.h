#pragma once 
#include "effect.h"
#include <iostream>

class Tremolo : public Effect{
    public: 
        Tremolo(std::string waveform, float modFreq);
        ~Tremolo();

        float process(float inputSample) override;
        void setModFreq(float freq);

    private: 
        Oscillator* oscillator;
        float modSignal;
};