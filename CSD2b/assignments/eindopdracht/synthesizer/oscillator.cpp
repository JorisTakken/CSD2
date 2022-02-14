#include <iostream>
#include "oscillator.h"

Oscillator::Oscillator(){
    sample = 0;
    phase = 0;
}

Oscillator::~Oscillator(){
}

// initialisation for oscillators, amplitude and samplerate
// FM_synth uses amplitude for ModDepth 
void Oscillator::initialize(double amp, double samplerate){ 
  this->amplitude = amp;
  this->samplerate = samplerate; 
}

// set new frequencie for oscillator
void Oscillator::setFrequency(float newFreq){
    this->frequency = newFreq;
}
        
// get new frequencie for oscillator
float Oscillator::getFrequency(){
    return frequency;
}

// tick function for calculating next sample of waveform done with this formula
void Oscillator::tick(){
  phase += frequency / samplerate;
  if(phase > 1) phase -= 1.0;
  calculate();
}


// get sample of calculated sample.
float Oscillator::getSample() {
  return sample;
}


