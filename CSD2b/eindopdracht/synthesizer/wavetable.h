#include <iostream>
#include "1_writeToFile.h"
#include "synth.h"

#include "ui_input.h"

#include "sine.h"
#include "saw.h"
#include "square.h"

#include "math.h"

#define MAX_OSCILLATORS 20

#pragma once

class Wavetable : public Synth{
    public:
        Wavetable();
        ~Wavetable();

        void updateOscFreq(int pitch,int oscillator_number) override;
        float getFrequency(int oscillator_number);

        void validate_numOscillators(int input_number_oscs);
        void initialize(std::string waveform[],int midiPitches[],int input_number_oscs);
        void write_waveform();

        float nextSample() override;  

    protected:
        float sample;
        int input_number_oscs;
        float number_oscs;

        Oscillator* oscillator[MAX_OSCILLATORS];
        int oscillator_number;

        float samp;
        std::string waveform;
        float frequencys;
        
};
