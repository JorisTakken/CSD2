#include "sine.h"
#include "bufferDebugger.h"
#include <iostream>
class Filter{
    public:
        Filter();
        ~Filter();

        float filter(int i);
        float filter_out();
        void plot_waveshaper();
    
    protected:
        float* buffer;
        float* writeBuf;
        Sine* sine;
};