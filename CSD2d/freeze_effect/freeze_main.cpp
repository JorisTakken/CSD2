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

  do{
    jack.readSamples(inbuffer,chunksize);
    for(unsigned int x=0; x<chunksize; x++){

      float input = inbuffer[x];
      record.write(inbuffer[x],recording);
      // cout << record.read() << endl;
      // outbuffer[2*x] = record.read();
      // outbuffer[2*x+1] = record.read();

      freeze.applyEffect(record.read(),outbuffer[2*x]);
      freeze1.applyEffect(record.read(),outbuffer[2*x+1]);
    }
    
    jack.writeSamples(outbuffer,chunksize*2);
  } 
  while(running);
}

int main(int argc, char **argv){
  char command='@';
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

      case 'w':
        cout << "WWWWWWW" << endl;
        break;

      case 'b':
        cout << "BBBBBBB" << endl;
        break;
    }
  }




  // while(command != 'q')
  // {
  //   if(keypressed()) {
  //     command = getchar();
  //   }
  //   usleep(100000);
  // }

  running=false;
  filterThread.join();

  jack.end();
}
