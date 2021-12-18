#include "saw.h"
#include "math.h"

Saw::Saw() : Oscillator(){

}

Saw::~Saw(){
}

void Saw::calculate() {
  sample = phase * 2.0 - 1.0;
  sample *= amplitude;
}


