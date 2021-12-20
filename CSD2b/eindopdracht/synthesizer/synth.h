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

        void setMidiPitch(int midiPitch);
        float getMidiPitch(); 
        float MTOF(int midiPitch);

    protected:        
        virtual float nextSample() = 0;

        int midiPitch;
};
