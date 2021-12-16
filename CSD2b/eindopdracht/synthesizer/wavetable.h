#include <iostream>

#pragma once

class Wavetable{
    public:
        Wavetable();

        ~Wavetable();
        
        void initialize(std::string waveform[],float frequencys[],int number_oscs);
        void write_waveform();
        void calculate();  

        
    protected:
        float samp;
        int number_oscs;
        std::string waveform;
        float frequencys;
        
        Oscillator* oscillator[];


        
};
