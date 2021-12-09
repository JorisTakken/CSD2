#include <iostream>
#include "oscillator.h"




Oscillator::Oscillator(std::string waveform, float frequency, float amplitude, int samplerate) : 
    frequency(frequency), amplitude(amplitude), samplerate(samplerate){
    sample = 0;
    phase = 0;
}

Oscillator::~Oscillator(){
}

float Oscillator::getSample() {
  return sample;
}


float Oscillator::tick() {
  phase += frequency / samplerate;
  if(phase > 1) phase -= 1.0;
  return phase;

}

