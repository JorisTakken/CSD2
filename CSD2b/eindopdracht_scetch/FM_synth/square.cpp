#include "square.h"
#include "math.h"

#define SAMPLERATE 44100

Square::Square() : Square(0,0,0){
}

Square::Square(
  float frequency,
  float amplitude,
  int samplerate) 
  : 
  Oscillator(frequency, amplitude, samplerate){
}

Square::~Square(){
}


void Square::calculate(){
  if(phase > 1){
      phase -= 1.0;
      }
    if (phase >= 0.5){
      sample = -1; 
    }else{
      sample = 1; 
    }
  // sample *= amplitude;
}