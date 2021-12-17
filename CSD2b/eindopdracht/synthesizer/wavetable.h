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
        
        void initialize(std::string waveform[],float frequencys[],int number_oscs);
        void write_waveform();
        void calculate();  
        float getSample();

        
    protected:
        float sample;

        float samp;
        int number_oscs;
        std::string waveform;
        float frequencys;
        
        Oscillator* oscillator[];


        
};
