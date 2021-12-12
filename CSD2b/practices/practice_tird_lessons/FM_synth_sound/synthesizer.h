#include <iostream>
#pragma once

class Synth{
    public:
        Synth();
        ~Synth();

        float getSample();
        virtual void tick();

    protected:
        float frequency;
        float amplitude;
        int samplerate;
        std::string waveform;
};