#include <iostream>
#include "multible_osc.h"

#define SAMPLERATE 44100

Multible_osc::Multible_osc(
    int number_of_oscillators,
    float array_of_frequencies[],
    float array_of_waves[], 
    float amplitude)
    : 
    number_of_oscillators(number_of_oscillators), 
    array_of_frequencies(array_of_frequencies[number_of_oscillators]),
    array_of_waves(array_of_waves[number_of_oscillators])
    amplitude(amplitude){

}

Multible_osc::~Multible_osc(){

}





