#include <iostream>

#include "sine.h"
#include "square.h"
#include "saw.h"

#include "delay.h"

class modDelay : public Delay{
    public: 
        modDelay(float chorusRate, float modDepth, float baseDelay);
        ~modDelay();

        float applyEffect(float input);

        // float map(float input, int x1, int x2 , float min, float max);
        // float mapLin(float normValue, float low, float high);
        float wrap(int point);

        int msToSamps(float miliseconds);

    protected:
        Delay* delay;

        float modDepth;
        float baseDelay;
        int writePoint;
        int readPoint;
        int size;
        int samplerate;
        float* buffer;
        Oscillator* oscillator;
 
};