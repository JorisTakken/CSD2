#include <iostream>
#include "synth.h"

#include "sine.h"
#include "saw.h"
#include "square.h"

#include "math.h"

#pragma once

class FM_synth : public Synth{
    public:
        FM_synth();
        ~FM_synth();

        void initialize(std::string waveformCarrier,std::string waveformModulator, int midiPitch,float ratio, float modDepth);

        void updateOscFreq(int pitch,int oscillator_number) override;
        float getFrequency();

        void setRatio(float ratio);
        float getRatio();

        float nextSample() override;

    protected:
        std::string waveformCarrier;
        std::string waveformModulator;

        float carrierFreq;
        float ratio;
        float modDepth;

        float modFrequency;
        float freq;
        float newFreq;
        float sample;

        Oscillator* carrier;
        Oscillator* modulator;

        
};

