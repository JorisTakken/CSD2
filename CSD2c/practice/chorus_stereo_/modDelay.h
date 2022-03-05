#include "delay.h"

class modDelay : public Delay{
    public: 
        modDelay(float chorusRate, float modDepth, float baseDelay);
        ~modDelay();

        void applyEffect(float& input, float& output) override;

        float map(float input, int x1, int x2 , float min, float max);

    protected:
        float modDepth;
        float delayTime;

        float* buffer;

};