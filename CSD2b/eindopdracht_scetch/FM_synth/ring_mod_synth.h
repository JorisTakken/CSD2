#include <iostream>
#include "synthesizer.h"

#pragma once

class RING_synth : public Synth{
    public:
        RING_synth(
        char waveCarrier,
        float carrierFreq ,
        char waveModulator,
        float modulatorFreq,
        float amplitude);

        ~RING_synth();
        
        void write_waveform();

        // void tick();
        // float getSample();
        void calculate() override;  

        
    protected:
        float car_and_mod;

        
};

