#include <iostream>
#include "oscillator.h"




Oscillator::Oscillator(std::string waveform, float frequency, float amplitude, int samplerate) : 
    frequency(frequency), amplitude(amplitude), samplerate(samplerate){
}

Oscillator::~Oscillator(){
}

void Oscillator::write_waveFile(std::string waveform){

}