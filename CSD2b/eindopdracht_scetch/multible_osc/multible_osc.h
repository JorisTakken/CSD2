#include <iostream>
#include "math.h"
#pragma once

#define NUMBER_OF_OSCILLATORS 100
class Multible_osc{
    public:
        Multible_osc(int number_of_oscillators,float array_of_frequencies[], float array_of_waves[],float amplitude);
        ~Multible_osc();

        void make_oscillators();

        
    protected:
        int number_of_oscillators;
        float array_of_frequencies[NUMBER_OF_OSCILLATORS];
        float array_of_waves[NUMBER_OF_OSCILLATORS];
        float amplitude;


};

