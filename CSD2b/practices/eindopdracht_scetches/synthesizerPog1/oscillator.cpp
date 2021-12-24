#include <iostream>
#include "oscillator.h"

Oscillator::Oscillator(){
    sample = 0;
    phase = 0;
}

Oscillator::~Oscillator(){
}

void Oscillator::initialize(double amp, double samplerate){ 
  this->amplitude = amp;
  this->samplerate = samplerate; 
}

void Oscillator::setFrequency(float newFreq){
    this->frequency = newFreq;
}
        
float Oscillator::getFrequency(){
    return frequency;
}

void Oscillator::tick(){
  phase += frequency / samplerate;
  if(phase > 1) phase -= 1.0;
  calculate();
}

float Oscillator::getSample() {
  return sample;
}


