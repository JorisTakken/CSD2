#include <iostream>
#include "oscillator.h"

Oscillator::Oscillator(float frequency, float amplitude, int samplerate) : 
    frequency(frequency), amplitude(amplitude), samplerate(samplerate){
    sample = 0;
    phase = 0;
}

Oscillator::~Oscillator(){
}



void Oscillator::initialize(double freq, double amp, double samplerate) 
{ 
  this->frequency = freq; 
  this->amplitude = amp;
  this->samplerate = samplerate; 
}

void Oscillator::setFrequency(float newFreq){
    this->frequency = newFreq;
}
        
float Oscillator::getFrequency(){
    return frequency;
}

float Oscillator::getSample() {
  return sample;
}

void Oscillator::tick(){
  phase += frequency / samplerate;
  if(phase > 1) phase -= 1.0;
  calculate();
}



