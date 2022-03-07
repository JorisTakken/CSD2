#include "delay.h"
#include "sine.h"

class modDelay : public Delay{
    public:
        modDelay(float chorusRate, float modDepth, int delayTimeMS, int samplerate);
        ~modDelay();

        float applyEffect(float input);
        int msToSamps(float miliseconds);
        
    protected:
        Oscillator* oscillator;
        Delay* delay;
        int delayTimeSamps;
        float modDepth;

};