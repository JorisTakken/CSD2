#include "sine.h"
#include "math.h"

// sine is a subclass of baseclass oscillator
Sine::Sine() : Oscillator(){
}

Sine::~Sine(){
}

void Sine::calculate(){
// formula for making a sine wave
  sample = sin(M_PI * 2 * phase);
  sample *= amplitude;
}



