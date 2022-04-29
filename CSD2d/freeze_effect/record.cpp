#include "record.h"

Rec::Rec(int size, int numSamplesDelay) : readIndex(0), writeIndex(0){
  this -> size = size;
  this -> numSamplesDelay = numSamplesDelay;
  buffer = new float [size];
  setDelaySamps(numSamplesDelay);
}

Rec::~Rec(){
  delete [] buffer;
  buffer = nullptr;
}

void Rec::setDelaySamps(float numSamplesDelay){
  readIndex = writeIndex - numSamplesDelay + size;
  readIndex = wrap(readIndex);
}

void Rec::write(float sample, bool recordNow){
  if (recordNow == true){
    if (writeIndex <= size){
    buffer[writeIndex++] = sample;
  }
  }
 
}

float Rec::read(){
  float sample = buffer[readIndex++];
  readIndex = wrap(readIndex);
  return sample;
}

int Rec::wrap(int head){
  if(head>=size) head -=size;
  return head;
}

