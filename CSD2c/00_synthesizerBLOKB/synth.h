#include <iostream>

#include "sine.h"
#include "saw.h"
#include "square.h"

#include "math.h"

#pragma once

//------------------------------------------------------------------
// synth is the baseclass for wavetable synth and FM synth
//------------------------------------------------------------------
class Synth{
    public:
        Synth();
        ~Synth();


        void setMidiPitch(int midiPitch,int oscillator_number);
        float getMidiPitch(); 
        float mtof(int midiPitch);
        
        // these functions are different for both synths thats why virual.
        //------------------------------------------------------------------
        // function whitch goes to de setFreqencie of the oscillator whitch is chosen
        virtual void updateOscFreq(int pitch,int oscillator_number) = 0;
        // calculation for synths 
        virtual float nextSample() = 0;
    protected:        
        int midiPitch;
};
