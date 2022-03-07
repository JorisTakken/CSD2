#include "modDelay.h"
 
modDelay::modDelay(float chorusRate, float modDepth, int delayTimeMS, int samplerate) : Delay(size, numSamplesDelay, feedback),
    modDepth(modDepth){
    int delayTimeSamps = msToSamps(delayTimeMS);
    this->delayTimeSamps = delayTimeSamps;

    oscillator = new Sine(chorusRate,samplerate);
    delay = new Delay(samplerate, 2, 0);
}

modDelay::~modDelay(){
}



float modDelay::applyEffect(float input) {
  // modSignal is a float
  float modSignal = oscillator->genNextSample() * modDepth; 
//   modSignal = modSignal * 1;
  /*
   * offset is a float, 
   * setDelayTimeNumSamples is an overloaded method: 
   * • one accepts an int
   * • one accepts a float --> use interpolated read from buffer 
   */
  
  float sample = delay->setDelayTimeNumSamples(modSignal + 1,input);
  return sample;
}

int modDelay::msToSamps(float miliseconds){
    return int((miliseconds * (44100 / 1000.0)) + 0.5);
}



// void ModDelay::applyEffect(float& input, float& output)
// { 
//   modSignal = osc->getNextSample() * modDepth;  // float
//   delayTimeSamples = modSignal + offset; // float
//   read_H_fp = (float) writeH - delayTimeSamples; // float
//   readH = (int) read_H_fp; // int
//   readHNext = readHNext + 1; 
//   // get decimal value
//   read_h_dec = read_H_fp - read_H; // float
//   // wrap heads
//   wrapH(readH); 
//   wrapH(readHNext);
  
//   output = linMap(read_h_dec, buffer[readH], buffer[readHNext]);

//   // write value to circular buffer
//   buffer[writeH++] = output * feedback + input;

//   wrapH(m_writeH);
// }