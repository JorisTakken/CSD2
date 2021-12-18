#include <iostream>
#include "1_writeToFile.h"

#include "sine.h"
#include "saw.h"
#include "square.h"

#include "math.h"

#define MAX_OSCILLATORS 20

#pragma once

class Wavetable{
    public:
        Wavetable();
        ~Wavetable();

        void setFrequency(float newFreq,int oscillator_number);
        float getFrequency(int oscillator_number);

        void validate_numOscillators(int input_number_oscs);
        void initialize(std::string waveform[],float frequencys[],int input_number_oscs);
        void write_waveform();
        void calculate();  
         float getSample();

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
