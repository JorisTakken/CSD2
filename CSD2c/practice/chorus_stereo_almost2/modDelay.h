#include "delay.h"
#include "sine.h"

class modDelay : public Delay{
    public:
        modDelay(float chorusRate, float modDepth, int delayTimeMS, int samplerate);
        ~modDelay();

        int msToSamps(float miliseconds);
        float wrap(int point);
        
    protected:
        void applyEffect(float& input, float& output) override;

        Oscillator* oscillator;
        Delay* delay;

        int delayTimeSamps;
        float modDepth;
        int size;
        int readNext;

        int baseDelay;

};
