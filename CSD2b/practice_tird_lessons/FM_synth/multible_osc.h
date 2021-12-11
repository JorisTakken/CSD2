#include <iostream>
#include "sine.h"
#include "saw.h"
#include "math.h"
#include "writeToFile.h"
#pragma once

class Multible_osc{
    public:
        Multible_osc(int number_of_oscillators,float array_of_frequencies[], float array_of_waves[],float amplitude);
        ~Multible_osc();

        
    protected:
        int number_of_oscillators;
        float array_of_frequencies[10];
        float array_of_waves[10];
        float amplitude;


};

