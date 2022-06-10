#include <string>
#include <iostream>
#include <math.h>
#include <thread>
#include <unistd.h> // sleep
#include "jack_module.h"
#include "keypress.h"
#include "bufferDebugger.h"

#include "record.h"
#include "freeze.h"
#include "delay.h"


using namespace std;
typedef unsigned int uint;

// for audio
unsigned long chunksize = 256;
JackModule jack;
float samplerate = 44100;
bool running = true;

Rec record(22100,500);
bool recording = false;

static void audio(){
  float inbuffer[chunksize];
  float outbuffer[chunksize * 2];

  Freeze freeze;
  Freeze freeze1;
  float freezerOutL;
  float freezerOutR;


  do{
    jack.readSamples(inbuffer,chunksize);
    for(unsigned int x=0; x<chunksize; x++){

      record.write(inbuffer[x],recording);
      float freezer = record.read();

      freeze.applyEffect(freezer,freezerOutL);
      freeze1.applyEffect(freezer,freezerOutR);
      outbuffer[2*x] = (freezerOutL + inbuffer[x]) / 4;
      outbuffer[2*x+1] = (freezerOutR + inbuffer[x]) / 4;

      // cout << inbuffer[x] << endl;

      // outbuffer[2*x] = inbuffer[x];
      // outbuffer[2*x+1] = inbuffer[x];
    }
    
    jack.writeSamples(outbuffer,chunksize*2);
  } 
  while(running);
}

int main(int argc, char **argv){
  // char command='@';
  jack.init(argv[0]);
  jack.autoConnect();
  jack.setNumberOfInputChannels(1);
  jack.setNumberOfOutputChannels(2);


  thread filterThread(audio);

  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;

      case 'd':
        cout << "DDDDDDD" << endl;
        recording = true;
        break;

      case 'f':
        cout << "WWWWWWW" << endl;
        recording = false;
        break;

    }
  }

  running=false;
  filterThread.join();

  jack.end();
}
