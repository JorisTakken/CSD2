#include <iostream>
#include "writeToFile.h"


#pragma once

class Oscillator{
    public:
        Oscillator(std::string waveform,float frequency, float amplitude, int samplerate);
        ~Oscillator();

        void write_waveFile(std::string waveform);

        float getSample();
        void tick(int next_samp);

    protected:
        float frequency;
        float amplitude;
        int samplerate;
        std::string waveform;
        // int argc;
        // char **argv;
};