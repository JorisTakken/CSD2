#include <iostream>
#include "oscillator.h"

Oscillator::Oscillator(float freq, float amp){
    std::cout << "inside oscillator   " << freq << std:: endl;
    this->amp = amp;
    this->freq = freq;
}

Oscillator::~Oscillator(){
}


void Oscillator::setFreq(float freq){
    if (freq > 0 || freq >= 20000){
        this->freq = freq;
    }
    else {
        std::cout << "freq is incorrect, try an other one" << freq << std:: endl;
    }
}

void Oscillator::getFreq(float freq){
    std::cout << freq << std:: endl;

}