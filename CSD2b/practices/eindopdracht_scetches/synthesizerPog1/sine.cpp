#include "sine.h"
#include "math.h"


Sine::Sine() : Oscillator(){
}

Sine::~Sine(){
}

void Sine::calculate(){
  sample = sin(M_PI * 2 * phase);
  sample *= amplitude;
}



