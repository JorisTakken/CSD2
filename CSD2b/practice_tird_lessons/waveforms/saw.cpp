#include "saw.h"
#include "math.h"

#define SAMPLERATE 44100


Saw::Saw(std::string waveform,float frequency,float amplitude,int samplerate){
    sample = 0;
    phase = 0;

    this->frequency = frequency;   
    this->amplitude = amplitude;    
    this->samplerate = samplerate;

}

Saw::~Saw(){
}

void Saw::setFrequency(float frequency){
}

void Saw::setAmplitude(float amplitude) {
}

float Saw::getSample() {
  return sample;
}

void Saw::tick(int next_samp){
    phase += frequency / SAMPLERATE;
    if(phase > 1){
      phase -= 1.0;
      }

    sample = (1.0 - phase) * 2 - 1; 
}


float Saw::getFrequency(){
  std::cout << "frequency" << frequency << "\n";
  return frequency;
}

float Saw::getAmplitude(){
  std::cout << "amplitude" << amplitude << "\n";
  return amplitude;
}
