#include <iostream>

#include "sine.h"
#include "saw.h"
#include "square.h"

#include "math.h"

#pragma once

class Synth{
    public:
        Synth();
        ~Synth();

        virtual void updateOscFreq(int pitch,int oscillator_number) = 0;

        void setMidiPitch(int midiPitch,int oscillator_number);
        float getMidiPitch(); 
        float mtof(int midiPitch);

        virtual float nextSample() = 0;
        // virtual void initializeWavetable(std::string waveform[],int midiPitches[],int input_number_oscs) = 0;
        
        
        
        // virtual void initializeFm(std::string waveformCarrier,std::string waveformModulator, int midiPitch,float ratio, float modDepth);
        // virtual void initializeWavetable(std::string waveform[],int midiPitches[],int input_number_oscs);


    protected:        
      

        int midiPitch;
};
