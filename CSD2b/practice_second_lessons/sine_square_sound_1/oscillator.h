#include <iostream>
#include "writeToFile.h"

#pragma once

class Oscillator{
    public:
        Oscillator(std::string waveform, float frequency, float amplitude, int samplerate);
        ~Oscillator();
        void changeWaveform(std::string waveform);
        void playWaveform();
        void makeListOfPoints();

    protected:
        std::string waveform;
        float frequency;
        float amplitude;
        int samplerate;
};