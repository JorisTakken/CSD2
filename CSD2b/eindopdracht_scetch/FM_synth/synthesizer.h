#include <iostream>
#pragma once

class Synth{
    public:
        Synth();
        ~Synth();

        void tick();
        float getSample();

    protected:
       float midiPitch; 
       double mtof(float pitch);
       double sample;
};