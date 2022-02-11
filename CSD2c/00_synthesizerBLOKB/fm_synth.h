#include <iostream>
#include "synth.h"

#include "sine.h"
#include "saw.h"
#include "square.h"

#include "math.h"

#pragma once

//------------------------------------------------------------------
// FM_synth is a subclass of Synth
//------------------------------------------------------------------
class FM_synth : public Synth{
    public:
        FM_synth();
        ~FM_synth();    

        // function initialize is for giving all necessary parameters to FM synth
        //------------------------------------------------------------------    
        void initialize(std::string waveformCarrier,std::string waveformModulator, int midiPitch,float ratio, float modDepth);

        // funcion goes directly to oscillator frequency
        // oscillator_number is not used in this class, only in wavetable synth
        void updateOscFreq(int pitch,int oscillator_number) override;
        float getFrequency();

        // you can set ratio of modulator
        void setRatio(float ratio);
        float getRatio();

        // calcutlate next sample with formula of an FM synth
        float nextSample() override;

    protected:
        std::string waveformCarrier;
        std::string waveformModulator;
        float carrierFreq;
        float ratio;
        float modDepth;

        float modFrequency;
        float freq;
        float newFreq;
        float sample;

        // oscillators for these object are not chosen yet
        // they will be chosen in Initialize function
        Oscillator* carrier;
        Oscillator* modulator;

        
};

