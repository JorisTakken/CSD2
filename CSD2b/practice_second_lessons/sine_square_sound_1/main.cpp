#include <iostream>
#include <thread>
#include "sine.h"
#include "square.h"
#include "jack_module.h"


int main(int argc,char **argv)
{
  JackModule jack;
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  std::string waveform_choose;
    std::cout << "witch waveform would you like to hear,\n";
    std::cin >> waveform_choose;
    std::cout << "__-_,\n";
  if (waveform_choose == "sine"){
    Sine sine("sine" ,220, 0.5, samplerate);
    float amplitude = 0.15;
    jack.onProcess = [&sine, &amplitude](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = sine.getSample() * amplitude;
      sine.tick();
    }
    amplitude = 0.5;
    return 0;
  };
  }




  
  else if (waveform_choose == "square"){ 
    Square square("sine" ,220, 0.5, samplerate);
    float amplitude = 0.15;
    jack.onProcess = [&square, &amplitude](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = square.getSample() * amplitude;
      square.tick();
    }
    amplitude = 0.5;
    return 0;
  };
  }

  










  jack.autoConnect();
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }
  return 0;
} 

