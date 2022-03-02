#include <iostream>
#pragma once 

class Waveshaper{
    public:
        Waveshaper(int buffersize);
        ~Waveshaper();

        void genWaveshape(float sharpness);
        void bufferWaveshaper(float input);



        float interpolation(float input);
        void plot_waveshaper();


        float map(float input, int x1, int x2 , float min, float max);

    protected:
        int buffersize;
        float* wavetableBuffer;
};

