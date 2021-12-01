#include "square.h"
#include "math.h"



Square::Square(float frequency,float amplitude) : frequency(frequency), amplitude(amplitude){
  sample = 0;
  phase = 0;
}

Square::~Square(){
}

void Square::setFrequency(float frequency){
}

void Square::setAmplitude(float amplitude) {
}


float Square::getSample() {
  return sample;
}

void Square::tick(){
    phase += frequency / SAMPLERATE;



    if ((phase / 5.0) >= 0.5){ 
    sample = 7.0;
    }
    else {
    sample = -100.0; 
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
