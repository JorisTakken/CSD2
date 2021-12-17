#include <iostream>
// #include "wavetable.h"
#include "1_writeToFile.h"


#include "sine.h"
#include "saw.h"
#include "square.h"


#include "math.h"

#pragma once

class Wavetable{
    public:
        Wavetable();
        ~Wavetable();

        void setFrequency(float newFreq,int oscillator_number);
        float getFrequency();


        
        void initialize(std::string waveform[],float frequencys[],int number_oscs);
        void write_waveform();
        void calculate();  
         float getSample();

    protected:
        float sample;
        int number_oscs;

        int oscillator_number;
        Oscillator* oscillator[4];


        float samp;
        std::string waveform;
        float frequencys;
        
        


        
};
