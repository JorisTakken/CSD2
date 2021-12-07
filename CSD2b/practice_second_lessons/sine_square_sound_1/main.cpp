#include <iostream>
#include <thread>
#include "sine.h"
#include "square.h"
#include "jack_module.h"
#include "writeToFile.h"



int main(int argc,char **argv)
{

  JackModule jack;
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  std::string choise = "sine";  

  Square square("sine",220, 0.5, samplerate);

  float amplitude = 0.15;
  jack.onProcess = [&square, &amplitude](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = square.getSample() * amplitude;
      square.tick();
    }
    return 0;
  };

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




   

  //end the program
  return 0;
} 

