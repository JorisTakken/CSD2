#include <iostream>
#include <thread>
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "writeToFile.h"

#define SAMPLERATE 44100

float outBuf[44100];

int main(int argc,char **argv){
  Square square("square",10, 1, SAMPLERATE);

  Sine sine2("sine",20, 1, SAMPLERATE);
  Sine sine("sine",10, 1, SAMPLERATE);
  Saw saw("saw",1, 1, SAMPLERATE);


  float amplitude = square.getAmplitude();

  for(unsigned int i = 0; i < SAMPLERATE; i++) {
    outBuf[i] = square.getSample() * amplitude;
    square.tick();
  }
    // WriteToFile file("1sine_and_saw_values.csv", true);
    // for(int i = 0; i < SAMPLERATE; i++) {

    // float saw_and_sine = (sine.getSample() * saw.getSample()) * 2;
    // file.write(std::to_string(saw_and_sine) + "\n");
    // sine.tick();
    // saw.tick();
    // }

    WriteToFile file("1sine_and_saw_values.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {

    float saw_and_sine = sine.getSample() / 2;
    file.write(std::to_string(saw_and_sine) + "\n");
    sine.tick();
   
    }


}

