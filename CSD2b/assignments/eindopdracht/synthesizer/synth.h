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


        void setMidiPitch(int midiPitch,int oscillator_number);
        float getMidiPitch(); 
        float mtof(int midiPitch);
        
        virtual void updateOscFreq(int pitch,int oscillator_number) = 0;
        virtual float nextSample() = 0;
    protected:        
        int midiPitch;
};
