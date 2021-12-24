#include <iostream>
#include "sine.h"
#include "saw.h"
#include "square.h"

#include "math.h"
#include "writeToFile.h"

#pragma once

class Synth{
    public:
        Synth(
            std::string wave_1,
            float waveFreq_1,
            std::string wave_2,
            float waveFreq_2,
            float amplitude,
            float ratio
        );

        virtual ~Synth();

        float setFrequency_carrier(float newFreqCar);       
        float getFrequency_carrier();        

        void initialize();

        void tick();
        float getSample();        

    protected:
        virtual void calculate() = 0;

        std::string wave_1;
        float waveFreq_1;
        std::string wave_2;
        float waveFreq_2;
        float amplitude;
        float sample;
        float ratio;

        float newFreqCar;
        float freqModulator;

        Oscillator* modulator; 
        Oscillator* carrier;
};