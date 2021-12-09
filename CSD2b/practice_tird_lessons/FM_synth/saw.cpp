#include "saw.h"
#include "math.h"

Saw::Saw(std::string waveform,float frequency,float amplitude,int samplerate) : 
  frequency(frequency),amplitude(amplitude),samplerate(samplerate){
    sample = 0;
    phase = 0;
}

Saw::~Saw(){
}

float Saw::getSample() {
  return sample;
}

void Saw::tick() {
  phase += frequency / samplerate;
  if(phase > 1) phase -= 1.0;
  sample = phase * 2.0 - 1.0;
  // sample *= amplitude;
}


