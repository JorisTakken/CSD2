#include <iostream>
#include <string>
#include <math.h>
#include <thread>
#include <unistd.h> // sleep
#include "jack_module.h"
#include "keypress.h"
#include "bufferDebugger.h"

#include "filter.h"
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

  Sine sine(500,samplerate);
  Sine sine2(500,samplerate);

  Filter filterL(Filter::filterType::lowpass, 1, 0.2);
  filterL.setDrywet(1);
  filterL.setCutoff(1);

  float previus = 0; 


  do {
    jack.readSamples(inbuffer,chunksize);
      for(unsigned int x=0; x<chunksize; x++)
      {
        // float val = (0.5*previus);
        // outbuffer[2*x] = (0.5*inbuffer[x])-(0.5*previus);
        // outbuffer[2*x] = (inbuffer[x]); 

      filterL.applyDryWet(inbuffer[x],outbuffer[2*x]);
      // filterR.applyDryWet(inbuffer[x],outbuffer[2*x+1]);  
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













