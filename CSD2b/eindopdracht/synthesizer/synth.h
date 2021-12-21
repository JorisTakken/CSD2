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

        virtual void updateOscFreq(float pitch) = 0;

        void setMidiPitch(int midiPitch);
        float getMidiPitch(); 


        float mtof(int midiPitch);

    protected:        
        virtual float nextSample() = 0;

        int midiPitch;
};
