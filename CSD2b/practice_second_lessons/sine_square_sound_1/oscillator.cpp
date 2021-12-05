#include <iostream>
#include "oscillator.h"
#include "sine.h"
#include "square.h"

using namespace std;

Oscillator::Oscillator(std::string waveform, float frequencie, float amplitude, int samplerate) : 
    waveform(waveform), frequencie(frequencie), amplitude(amplitude), samplerate(samplerate){
        if (waveform == "sine"){
            Sine sine(frequencie,amplitude);
        }
        if (waveform == "square"){
            Square Square(frequencie,amplitude);
        }
 
}

Oscillator::~Oscillator(){

}

void Oscillator::changeWaveform(std::string waveform){

}

void Oscillator::playWaveform(std::string waveform, float frequencie, float amplitude, int samplerate){

    jack.onProcess = [&sine, &amplitude](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = sine.getSample() * amplitude;
      sine.tick();
    }

}