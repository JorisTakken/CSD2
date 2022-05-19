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

void Rec::write(float sample, bool &recording){
  if (recording == true){
    if (writeIndex <= size){
    buffer[writeIndex++] = sample;
    }else{
      recording = false;
    }
  }
}

void Rec::clear(){
  for (int i = 0; i < size; i++){
    buffer[i] = 0;
  }
}

float Rec::read(){
  float envelope;
  float sample = buffer[readIndex++];
  readIndex = wrap(readIndex);

  // envelope
  if (readIndex < size / 2){envelope = linMap(readIndex,0,size,0,1);} 
  else {envelope = linMap(readIndex,0,size,1,0);}
  return sample * envelope;
}

int Rec::wrap(int head){
  if(head>=size) head -=size;
  return head;
}

float Rec::linMap(float input, float x1, float x2, float min, float max){
    float value = (min * (x2 - input) + max * (input - x1)) / (x2 - x1);
    return value;
}


