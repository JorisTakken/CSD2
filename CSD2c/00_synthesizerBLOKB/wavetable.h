#include <iostream>
#include "synth.h"

#include "sine.h"
#include "saw.h"
#include "square.h"

#include "math.h"

#define MAX_OSCILLATORS 20

#pragma once

//------------------------------------------------------------------
// Wavetable is a subclass of Synth
// its acctualy a ring modulator but you can choose as many oscillators as you want.
//------------------------------------------------------------------
class Wavetable : public Synth{
    public:
        Wavetable();
        ~Wavetable();

        // initialisation for oscilators
        void initialize(std::string waveform[],int midiPitches[],int input_number_oscs);

        // functions overide from bassclass
        // updateFreq is to change oscillator frequency
        void updateOscFreq(int pitch,int oscillator_number) override;
        float getFrequency(int oscillator_number);

        // next sample is to caluculate next sample with specific formula
        float nextSample() override;  


    protected:

        float sample;
        int input_number_oscs;
        float number_oscs;

        // program doesnt know witch oscillator it will be
        // make 20 oscillators already and UI will say if its to many oscillators
        Oscillator* oscillator[MAX_OSCILLATORS];
        int oscillator_number;

        float samp;
        std::string waveform;
        float frequencys;
        
};
