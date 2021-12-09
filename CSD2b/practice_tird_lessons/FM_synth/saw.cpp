#include "saw.h"
#include "math.h"

Saw::Saw(std::string waveform,float frequency,float amplitude,int samplerate) : Oscillator(waveform, frequency, amplitude, samplerate),
  frequency(frequency),amplitude(amplitude),samplerate(samplerate){

}

Saw::~Saw(){
}

void Saw::calculate() {
  sample = tick() * 2.0 - 1.0;

  // sample *= amplitude;
}


