#include "saw.h"
#include "math.h"

// saw is a subclass of baseclass oscillator
Saw::Saw() : Oscillator(){}

Saw::~Saw(){}

// formula for making a saw wave
void Saw::calculate() {
  sample = phase * 2.0 - 1.0;
  sample *= amplitude;
}


