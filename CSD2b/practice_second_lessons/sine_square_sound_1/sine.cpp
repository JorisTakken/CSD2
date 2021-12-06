#include "sine.h"
#include "math.h"

Sine::Sine(std::string waveform,float frequency,float amplitude,int samplerate) : Oscillator(waveform,frequency, amplitude, samplerate), 
  frequency(frequency), amplitude(amplitude), samplerate(samplerate){
    sample = 0; 
    phase = 0;
}

Sine::~Sine(){
}

void Sine::setFrequency(float frequency){
  if(frequency > 0 && frequency < 22050) {
    this->frequency = frequency;
  } else {
    std::cout << "The frequency value is incorrect"
    << " please present a value in the interval [0, 22049]\n";
  }
}

void Sine::setAmplitude(float amplitude) {
  if(amplitude > 0 && amplitude < 1) {
    this->amplitude = amplitude;
  } else {
    std::cout << "The amplitude value is incorrect"
    << " please present a value in the interval [0, 1]\n";
  }
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





float Sine::getFrequency(){
  std::cout << "frequency" << frequency << "\n";
  return frequency;
}

float Sine::getAmplitude(){
  std::cout << "amplitude" << amplitude << "\n";
  return amplitude;
}
