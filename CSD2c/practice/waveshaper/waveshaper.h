#include <iostream>
#pragma once 
#include "math.h"
#include "bufferDebugger.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "oscillator.h"


//random function
#include <cstdlib>
#include <ctime>


class Waveshaper{
    public:
        Waveshaper(int buffersize);
        ~Waveshaper();

         enum WaveChoise {SINE = 0, SAW, SQUARE};

        void genWaveshape(float sharpness);
        void bufferWaveshaper(float input,int x);
        void genWaveshapeOscillator(WaveChoise wave, float freq);   
        void genWaveshapeNoise(float noiseVal,int i );



        float interpolation(float input);
        void plot_waveshaper();


        float map(float input, int x1, int x2 , float min, float max);

    protected:
        int buffersize;
        float* wavetableBuffer;
        Oscillator* oscillator;
};

