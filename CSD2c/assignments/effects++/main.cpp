#include <iostream>
#include <string>
#include <math.h>
#include <thread>
#include <unistd.h> // sleep
#include "jack_module.h"
#include "keypress.h"
#include "bufferDebugger.h"

#include "waveshaper.h"
#include "tremolo.h"
#include "chorus.h"
#include "filter.h"

#include "delay.h"

#define WRITE_TO_FILE 0
#define WRITE_NUM_SAMPLES 44100
#define SAMPLERATE 44100 

// functions to make random waveshaper
// =========================================
#define BUFFERSIZE 1000
float totaal;
int number_ints = 1000; //3000 - -3000
void job_1(){
    for (int i = 0; i< number_ints; i++){
        totaal++;
    }
}
void job_2(){
    for (int i = 0; i< number_ints; i++){
        totaal--;
    }
}
// =========================================

unsigned long chunksize=256;
JackModule jack;
unsigned long samplerate=44100; // default

bool running=true;

static void filter(){
  float *inbuffer = new float[chunksize];
  float *outbuffer = new float[chunksize*2];

  // float modFreq, float modDepth, int delayMS, float feedback, float samplerate
  Effect* effectL = new Chorus(1,1,100,0.0,samplerate);
  Effect* effectR = new Chorus(1,1,50,0.0,samplerate);

  // Effect* effectR = new Filter(Filter::filterType::highpass, 1, 2);
  // Effect* effectL = new Filter(Filter::filterType::highpass, 1, 2);

  // ((Waveshaper*)effectL)->genWaveshape(10.0);
  // ((Waveshaper*)effectR)->plot_waveshaper();

  // chooseEffect(chorus);


  effectL->setDrywet(1);
  effectR->setDrywet(1);
  

      do {
        jack.readSamples(inbuffer,chunksize);
          for(unsigned int x=0; x<chunksize; x++)
          {
          
          float input = inbuffer[x];
          effectR->applyDryWet(input,outbuffer[2*x]);
          effectL->applyDryWet(input,outbuffer[2*x+1]);
          }

        jack.writeSamples(outbuffer,chunksize*2);
        
      }while(running);
    
    

} // filter()



int main(int argc,char **argv){
char command='@';
  jack.setNumberOfInputChannels(1);
  // jack.setNumberOfOutputChannels(2);
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













