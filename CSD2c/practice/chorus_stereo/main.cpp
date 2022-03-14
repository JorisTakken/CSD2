#include <iostream>
#include <string>
#include <math.h>
#include <thread>
#include <unistd.h> // sleep
#include "jack_module.h"
#include "keypress.h"
#include "bufferDebugger.h"

// #include "effect.h"
#include "chorus.h"
#include "sine.h"

#define WRITE_NUM_SAMPLES 44100
#define SAMPLERATE 44100 

unsigned long chunksize=256;

JackModule jack;
unsigned long samplerate=44100; // default

bool running=true;

#define BUFFERSIZE 1000

static void filter(){
float *inbuffer = new float[chunksize];
float *outbuffer = new float[chunksize*2];

    // Sine sine(1,samplerate);
  //  float modFreq, float modDepth, int delayMS, float feedback, float samplerate
    Chorus chorusL(0.5,1,40,0,samplerate); 
    Chorus chorusR(0.25,1,20,0,samplerate); 
    chorusL.setDrywet(1);
    chorusR.setDrywet(1);

  do {
    jack.readSamples(inbuffer,chunksize);
      for(unsigned int x=0; x<chunksize; x++)
      {
      chorusL.applyDryWet(inbuffer[x],outbuffer[2*x]);
      chorusR.applyDryWet(inbuffer[x],outbuffer[2*x+1]);
      }
    jack.writeSamples(outbuffer,chunksize*2);
    
  }while(running);
} // filter()



int main(int argc,char **argv){
char command='@';
  jack.setNumberOfInputChannels(1);
  jack.setNumberOfOutputChannels(2);
  jack.init(argv[0]); // use program name as JACK client name
  jack.autoConnect();
  samplerate=jack.getSamplerate();
  std::cerr << "Samplerate: " << samplerate << std::endl;

  std::thread filterThread(filter);

  while(command != 'q')
  {
    if(keypressed()) {
      command = getchar();

      if(command == '+' || command == '=') {
        std::cout << "je hebt geklikt baas" << std::endl;
      };
      if(command == '-'){
        std::cout << "je hebt geklikt baas" << std::endl;
      };
    }
    usleep(100000);
  }

  running=false;
  filterThread.join();

  jack.end();

  return 0;
} // main()













