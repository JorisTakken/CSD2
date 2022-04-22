#pragma once
#include <iostream>
#include "circBuffer.h"
#include "sine.h"
#include "effect.h"

class Chorus : public Effect{
    public:
        Chorus(float modFreq, float modDepth, int delayMS,float feedback, float samplerate);
        ~Chorus();

        void setDelayMS(float delayMilsec);
        void setModFreq(float newModFreq);
        void setModDepth(float newModDepth);


    protected:
        void processEffect(float &input, float &output) override;

        CircBuffer* circBuffer;

        int size;
        int delaySamps;
        float modFreq;
        float modulation;
        float feedback;
        int delayMS;
        float modDepth;



};
