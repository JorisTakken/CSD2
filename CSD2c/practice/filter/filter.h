#include <iostream>
#include "effect.h"

class Filter : public Effect{
    public:
        Filter();
        ~Filter();

        void processEffect(float& input,float& output) override;
        // float filter_out();
        void plot_waveshaper();
        int wrap(int head);

    
    protected:
        float* buffer;

        int readIndex = 0;
        int writeIndex = 0;

};