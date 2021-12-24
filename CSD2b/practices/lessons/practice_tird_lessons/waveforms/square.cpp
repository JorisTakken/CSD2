#include "square.h"
#include "math.h"

#define SAMPLERATE 44100


Square::Square(std::string waveform,float frequency,float amplitude,int samplerate) : 
  frequency(frequency), amplitude(amplitude), samplerate(samplerate){
    sample = 0;
    phase = 0;
}

Square::~Square(){
}

void Square::setFrequency(float newfrequency){
  if(newfrequency > 0 && newfrequency < 22050) {
    newfrequency = frequency;
  } else {
    std::cout << "The frequency value is incorrect"
    << " please present a value in the interval [0, 22049]\n";
  }
}

void Square::setAmplitude(float newAmplitude) {
  if(newAmplitude > 0 && newAmplitude < 1) {
    newAmplitude = amplitude;
  } else {
    std::cout << "The amplitude value is incorrect"
    << " please present a value in the interval [0, 1]\n";
  }
}

float Square::getSample() {
  return sample;
}

void Square::tick(){
    phase += frequency / SAMPLERATE;
    if(phase > 1){
      phase -= 1.0;
      }
    if (phase >= 0.5){
      sample = -1; 
    }else{
      sample = 1; 
    }

    // sample = phase * 0.5 - 1;

    // for (int i = 0; i < SAMPLERATE; i++){
    //   if (sample > 0.0){sample = amplitude * -1;}
    //   else{sample = amplitude * 1;}
    // }
}

float Square::getFrequency(){
  std::cout << "frequency" << frequency << "\n";
  return frequency;
}

float Square::getAmplitude(){
  std::cout << "amplitude" << amplitude << "\n";
  return amplitude;
}
