#include <iostream>
#include "sine.h"
#include "saw.h"
#include "square.h"

#include "math.h"
#include "writeToFile.h"

#include "synthesizer.h"

#pragma once

class RING_synth : public Synth{
    public:
        RING_synth(
        std::string waveCarrier,
        float carrierFreq ,
        std::string waveModulator,
        float modulatorFreq,
        float amplitude);

        ~RING_synth();
        
        void write_waveform();

        float calculate() override;  
        void tick();
        float getSample();
        
    protected:

        float car_and_mod;

        
};

