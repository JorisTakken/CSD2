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
    array_of_frequencies(array_of_frequencies[10]),
    array_of_waves(array_of_waves[10]),
    amplitude(amplitude){

}

Multible_osc::~Multible_osc(){
}

void Multible_osc::make_oscillators(){
    for (int i = 0; i < number_of_oscillators; i++){
        array_of_frequencies[i];
    }
}





