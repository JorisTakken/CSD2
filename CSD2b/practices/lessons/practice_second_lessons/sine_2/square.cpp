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




float Square::getSample() {
  return sample;
}

void Square::tick(){
    phase += frequency / SAMPLERATE;
    sample = sin(M_PI * 2 * phase);

    for (int i = 0; i < SAMPLERATE; i++){
      if (sample > 0.0){sample = amplitude * -1;}
      else{sample = amplitude * 1;}
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
