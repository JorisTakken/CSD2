#include <string>
#include <iostream>
#include <math.h>
#include <thread>
#include <unistd.h> // sleep
#include "jack_module.h"
#include "keypress.h"
#include "bufferDebugger.h"




// for audio
unsigned long chunksize = 256;
JackModule jack;
float samplerate = 44100;
bool running = true;


static void audio(){
  float inbuffer[chunksize];
  float outbuffer[chunksize * 2];

  do{
    jack.readSamples(inbuffer,chunksize);
    for(unsigned int x=0; x<chunksize; x++){
      float input = inbuffer[x];

      outbuffer[2*x+1] = input;
      outbuffer[2*x] = input;
    }

    jack.writeSamples(outbuffer,chunksize*2);
  } while(running);
}




int main(int argc, char **argv){
  char command='@';
  jack.init(argv[0]);
  jack.autoConnect();
  jack.setNumberOfInputChannels(2);
  jack.setNumberOfOutputChannels(2);

  std::thread audioThread(audio);

  while(command != 'q')
  {
    if(keypressed()) {
      command = getchar();
    }
    usleep(100000);
  }

  running=false;
  audioThread.join();

  jack.end();
}
