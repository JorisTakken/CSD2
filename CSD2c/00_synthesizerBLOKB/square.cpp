#include "square.h"
#include "math.h"

#define SAMPLERATE 44100

// sine is a subclass of baseclass oscillator
Square::Square() : Oscillator(){}

Square::~Square(){}

// formula for making a squarewave
void Square::calculate(){
  if(phase > 1){
      phase -= 1.0;
      }
    if (phase >= 0.5){
      sample = -1; 
    }else{
      sample = 1; 
    }
  sample *= amplitude;
}