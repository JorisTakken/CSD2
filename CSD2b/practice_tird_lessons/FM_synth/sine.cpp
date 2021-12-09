#include "sine.h"
#include "math.h"

Sine::Sine(std::string waveform,float frequency,float amplitude,int samplerate) : Oscillator(waveform,frequency, amplitude, samplerate), 
  frequency(frequency), amplitude(amplitude), samplerate(samplerate){
    sample = 0; 
    phase = 0;
}

Sine::~Sine(){
}

float Sine::getSample() {
  return sample;
}

void Sine::tick(){
  phase += frequency / SAMPLERATE;
  sample = sin(M_PI * 2 * phase);
}

void Sine::list_of_values(std::string value_sine){
    for(int i = 0; i < 100; i++) {
      values_sine[i] = value_sine;
    }

}






