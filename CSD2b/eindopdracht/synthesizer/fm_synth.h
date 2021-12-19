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

        void setCarrierFrequency(float newFreq);
        float getCarrierFrequency();

        void setModulationIndex();
        float getModulationIndex();

        void calculateCarrierFreq();



        void validate_numOscillators(int input_number_oscs);
        void initialize(std::string waveform[],float frequencys[],int input_number_oscs);
        void write_waveform();
        void calculate();  
        float getSample();

    protected:
        float sample;
        float samp;
        float number_oscs;
        float carrierFreq;
        float modulatorFreq;

        Oscillator* carrier;
        Oscillator* modulator;

        std::string waveform;
        float frequencys;    
        float modulationIndex;
};

