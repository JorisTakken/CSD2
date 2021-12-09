#include "sine.h"
#include "math.h"

Sine::Sine(std::string waveform,float frequency,float amplitude,int samplerate) : Oscillator(waveform,frequency, amplitude, samplerate), 
  frequency(frequency), amplitude(amplitude), samplerate(samplerate){
}

Sine::~Sine(){
}

void Sine::calculate(){
  sample = sin(M_PI * 2 * tick());
}




