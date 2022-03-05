#include "modDelay.h"

// chorusrate = frequencie
// moddepth = from 0 - 1
modDelay::modDelay(float chorusRate, float modDepth, float baseDelay) : Delay(44100, baseDelay, feedback),
    delayTime(baseDelay),modDepth(modDepth){

    buffer = new float[44100];
    oscillator = new Sine(chorusRate, samplerate);

}
modDelay::~modDelay(){

}



// ModDelay is a derived class from Delay 
// Effect <-- Delay <-- ModDelay
void modDelay::applyEffect(float& input, float& output){ 
  int readPoint = 0;
  int writePoint = 0;

  float modSignal = oscillator->genNextSample() * modDepth;  // float
  numSamplesDelay = modSignal + 0.5; // float
  std::cout << numSamplesDelay << " num samps delay" << std::endl;
  float read_H_fp = (float) writePoint - numSamplesDelay; // float
  readPoint = (int) read_H_fp; // int
  int readHNextpoint =+ 1; 

  // get decimal value
  int read_h_dec = read_H_fp - readPoint; // float
  // wrap heads
  wrap(readPoint); 
  wrap(readHNextpoint);
  
  output = map(read_h_dec, 0,1, buffer[readPoint], buffer[readHNextpoint]);

  // write value to circular buffer
  buffer[writePoint++] = output + input;

  wrap(writePoint);
}

float modDelay::map(float input, int x1, int x2 , float min, float max){
    // STARTING AT A X VALUE
    float value = (min * (x2 - input) + max * (input - x1)) / (x2 - x1);    
    return value;
}