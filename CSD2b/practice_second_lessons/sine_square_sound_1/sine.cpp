#include "sine.h"
#include "math.h"



Sine::Sine(float frequency,float amplitude) : frequency(frequency), amplitude(amplitude){
  sample = 0;
  phase = 0;
}

Sine::~Sine(){
}

void Sine::setFrequency(float frequency){
}

void Sine::setAmplitude(float amplitude) {
}


float Sine::getSample() {
  return sample;
}

void Sine::tick(){
  phase += frequency / SAMPLERATE;
  sample = sin(M_PI * 2 * phase);
}


void Sine::list_of_values(std::string value_sine){
    for(int i = 0; i < 100; i++) {
      values_sine[i] = value_sine;
    }

}

float Sine::getFrequency(){
  std::cout << "frequency" << frequency << "\n";
  return frequency;
}

float Sine::getAmplitude(){
  std::cout << "amplitude" << amplitude << "\n";
  return amplitude;
}
