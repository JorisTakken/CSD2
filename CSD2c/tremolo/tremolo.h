#pragma once 
#include "sine.h"
#include "square.h"
#include "saw.h"


#include <iostream>

class Tremolo{
    public: 
        Tremolo(std::string waveform, float modFreq, int samplerate);
        ~Tremolo();

        float process(float sample);
        void setModFreq(float freq);

    private: 
        Oscillator* oscillator;
        float modSignal;
};