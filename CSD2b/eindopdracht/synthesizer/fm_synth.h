#include <iostream>
#include "1_writeToFile.h"

#include "sine.h"
#include "saw.h"
#include "square.h"

#include "math.h"

#define MAX_OSCILLATORS 20

#pragma once

class FM_synth{
    public:
        FM_synth();
        ~FM_synth();
        void initialize(std::string waveform,float frequency,float ratio, float mod_index);

        void calcModulator_freq();
        float make_modulator();
        void calcCarrier_freq();

        void setFrequency(float newFreq);
        float getFrequency();


        float sound();
        void write_waveform();
        // float getSample();

    protected:
        std::string waveform;
        float frequency;
        float ratio;
        float mod_index;

        float modFrequency;
        float modAmplitude;
        float modulation_depth;
        float freq;
        float newFreq;

        float sample;
        float samp;

        Oscillator* carrier;
        Oscillator* modulator;

        float modulationIndex;

        
};

