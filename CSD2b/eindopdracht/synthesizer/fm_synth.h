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

        void updateOscFreq(float pitch) override;

        void setRatio(float ratio);
        float getRatio();
        float getFrequency();


        float nextSample() override;

    protected:
        std::string waveformCarrier;
        std::string waveformModulator;

        float frequency;
        float ratio;
        float mod_index;

        float carrierFreq;

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

