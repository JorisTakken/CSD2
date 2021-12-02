#include "square.h"
#include "math.h"



Square::Square(float frequency,float amplitude) : frequency(frequency), amplitude(amplitude){
  phase = 0;
}

Square::~Square(){
}

void Square::setFrequency(float frequency){
}

void Square::setAmplitude(float amplitude) {
}

float Square::getSample2() {
  return sampleVal;
}


float Square::getSample(int i) {
  return sample[i];
}

void Square::tick(){
    phase += frequency / SAMPLERATE;
    sampleVal = sin(M_PI * 2 * phase);

    for (int i = 0; i < SAMPLERATE; i++){
    if (sampleVal < 0.0){
      sample[i] = amplitude * -1;
    }
    if(sampleVal > 0.0){
      sample[i] = amplitude * -1;
    }
    std::cout << "sample" << i << "_"<< sample[i] << "\n";
    }
    



}


float Square::getFrequency(){
  std::cout << "frequency" << frequency << "\n";
  return frequency;
}

float Square::getAmplitude(){
  std::cout << "amplitude" << amplitude << "\n";
  return amplitude;
}
