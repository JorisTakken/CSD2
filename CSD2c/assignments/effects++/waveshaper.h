#include <iostream>
#pragma once 
#include "math.h"
#include "bufferDebugger.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "oscillator.h"
#include "effect.h"

//random function
#include <cstdlib>
#include <ctime>


class Waveshaper : public Effect{
    public:
        Waveshaper(int buffersize);
        ~Waveshaper();

        enum WaveChoise {SINE = 0, SAW, SQUARE};

        void genWaveshape(float sharpness);
        void genWaveshapeOscillator(WaveChoise wave, float freq);   
        void genWaveshapeNoise(float noiseVal,int i);

        void processEffect(float &input, float &output) override;

        void plot_waveshaper();


        float map(float input, int x1, int x2 , float min, float max);

    protected:
        int buffersize;
        float* wavetableBuffer;
};

