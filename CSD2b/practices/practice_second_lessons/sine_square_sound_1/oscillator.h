#include <iostream>
#include "writeToFile.h"
#include "jack_module.h"






#pragma once

class Oscillator{
    public:
        Oscillator(std::string waveform,float frequency, float amplitude, int samplerate);
        ~Oscillator();

        void playWaveform();
        void write_waveFile(std::string waveform);

    protected:
        float frequency;
        float amplitude;
        int samplerate;
        std::string waveform;
        // int argc;
        // char **argv;
};