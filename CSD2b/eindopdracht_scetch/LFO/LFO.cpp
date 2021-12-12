#include "LFO.h"
#include "math.h"

Lfo::Lfo() : Lfo(0,0,0){}

Lfo::Lfo(
  float frequency,
  float amplitude,
  int samplerate) 
  : 
  Oscillator(frequency, amplitude, samplerate){
}

Lfo::~Lfo(){
}

void Lfo::calculate(){
  sample = sin(M_PI * 2 * phase);
  sample *= amplitude;
}



