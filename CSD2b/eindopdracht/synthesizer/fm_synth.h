#include <iostream>
#include "1_writeToFile.h"
#include "synth.h"

#include "sine.h"
#include "saw.h"
#include "square.h"

#include "math.h"

#define MAX_OSCILLATORS 20

#pragma once

class FM_synth : public Synth{
    public:
        FM_synth();
        ~FM_synth();

        void write_waveform();
        void initialize(std::string waveformCarrier,std::string waveformModulator, int midiPitch,float ratio, float mod_index);

        void calcModulator_freq();
        float make_modulator();
        void calcCarrier_freq();

        void setPitch(int pitch);
        float getFrequency();


        float nextSample();

    protected:
        std::string waveformCarrier;
        std::string waveformModulator;

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

