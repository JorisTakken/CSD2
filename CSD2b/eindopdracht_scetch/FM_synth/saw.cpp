#include "saw.h"
#include "math.h"

Saw::Saw() : Saw(0,0,0){

}

Saw::Saw(float frequency,float amplitude,int samplerate) : Oscillator(frequency, amplitude, samplerate){

}

Saw::~Saw(){
}

void Saw::calculate() {
  sample = phase * 2.0 - 1.0;
  // sample *= amplitude;
}


