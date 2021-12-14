#include "sine.h"
#include "math.h"

Sine::Sine() : Sine(0,0,0){}

Sine::Sine(
  float frequency,
  float amplitude,
  int samplerate) 
  : 
  Oscillator(frequency, amplitude, samplerate){
}

Sine::~Sine(){
}

void Sine::calculate(){
  sample = sin(M_PI * 2 * phase);
  // sample *= amplitude;
}



