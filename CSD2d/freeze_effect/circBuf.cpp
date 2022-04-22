#include "circBuf.h"

Circ::Circ(int size, int numSamplesDelay) : readIndex(0), writeIndex(0){
  this -> size = size;
  this -> numSamplesDelay = numSamplesDelay;
  buffer = new float [size];
  setDelaySamps(numSamplesDelay);
}

Circ::~Circ(){
  delete [] buffer;
  buffer = nullptr;
}

void Circ::setDelaySamps(float numSamplesDelay){
  readIndex = writeIndex - numSamplesDelay + size;
  readIndex = wrap(readIndex);
}

void Circ::write(float sample){
  buffer[writeIndex++] = sample;
  writeIndex = wrap(writeIndex);
}

float Circ::read(){
  float sample = buffer[readIndex++];
  readIndex = wrap(readIndex);
  return sample;
}

int Circ::wrap(int head){
  if(head>=size) head -=size;
  return head;
}

