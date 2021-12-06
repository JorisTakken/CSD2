#include <iostream>
#include "oscillator.h"




Oscillator::Oscillator(std::string waveform, float frequency, float amplitude, int samplerate) : 
    frequency(frequency), amplitude(amplitude), samplerate(samplerate){
}

Oscillator::~Oscillator(){
}



void Oscillator::playWaveform(){

  // here should be the jack module i think



      // JackModule jack;
      //   jack.onProcess = [&sine, &amplitude](jack_default_audio_sample_t *inBuf,
      //   jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

      //   for(unsigned int i = 0; i < nframes; i++) {
      //     outBuf[i] = sine.getSample() * amplitude;
      //     sine.tick();
      //   }
      //   amplitude = 0.5;
      //   return 0;
      // };

      // jack.autoConnect();
}

void Oscillator::write_waveFile(std::string waveform){

  // here you can write the file to python plotter






        // if (waveform == "sine") {
        //     Sine sine_make(frequency,amplitude,samplerate);

        //     WriteToFile waveform_file("square_values.csv", true);
        //     for(int i = 0; i < samplerate; i++) {
        //         waveform_file.write(std::to_string(sine_make.getSample()) + "\n");
        //         sine_make.tick();
        //     }
        // }
        // else if (waveform == "square"){
        //     Square square_make(frequency,amplitude,samplerate);

        //     WriteToFile waveform_file("square_values.csv", true);
        //     for(int i = 0; i < samplerate; i++) {
        //         waveform_file.write(std::to_string(square_make.getSample()) + "\n");
        //         square_make.tick();
        //     }
        // }

    
}