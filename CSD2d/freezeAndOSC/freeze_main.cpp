// THANK YOU MARC GROENEWEGEN FOR THE OSC SCRIPT I USED TO RECEIVE OSC
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

#include "osc.h"


using namespace std;
typedef unsigned int uint;

// for audio
unsigned long chunksize = 256;
JackModule jack;
float samplerate = 44100;
bool running = true;

Rec record(22100,500);
bool recording = false;


  int val;
// subclass OSC into a local class so we can provide our own callback
class localOSC : public OSC{
  int realcallback(const char *path,const char *types,lo_arg **argv,int argc){
  string msgpath=path;
    // cout << "path: " << msgpath << endl;
    if(!msgpath.compare("/compass")){
      int int1 = argv[0]->i;
      // cout << "Message: " << int1 << " " << endl;
        val = int1;
    }
    return 0;
  } // realcallback()
};


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
    }
    jack.writeSamples(outbuffer,chunksize*2);
  } 
  while(running);
}


// static float OSCMessage(){
 
// }

int main(int argc, char **argv){
  // char command='@';
  jack.init(argv[0]);
  jack.autoConnect();
  jack.setNumberOfInputChannels(1);
  jack.setNumberOfOutputChannels(2);

  thread filterThread(audio);
  // thread OSCThread(OSCMessage);

  localOSC osc;
  string serverport="7777";
    osc.init(serverport);
    osc.set_callback("/compass","i");
    cout << "Listening on port " << serverport << endl;
    osc.start();
    while(true){
      if (val > 80 || val < 120){
        cout << "rec " << endl;
        recording = true;

      }else {
        
        
      }
    }
  
    

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
  // OSCThread.join();

  jack.end();
}
