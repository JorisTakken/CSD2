#include "circBuf.h"
#include <iostream>
#include "sine.h"
#include "square.h"
#include "saw.h"
#include "writeToFile.h"
#include "jack_module.h"

#define WRITE_NUM_SAMPLES 44100
#define WRITE_TO_FILE 0

int main(int argc,char **argv){
    JackModule jack;
    jack.init(argv[0]);

    // FLOAT 1 = BUFFERSIZE
    // FLOAT 2 = IS SAMPLEDELAY 
     
    circBuf circ(44100, 1231);
    // dry = 0 
    // wet = 1 
    circ.setDrywet(1);
    Sine sine(200,44100);




#if WRITE_TO_FILE
    WriteToFile fileWriter("output.csv", true);
    
    jack.onProcess = [&circ, &fileWriter, &sine](jack_default_audio_sample_t* inBuf,
      jack_default_audio_sample_t* outBuf, jack_nframes_t nframes) {
#else
    // ---------------------------
    // FOR JACK AUDIO
    // ---------------------------
    jack.onProcess = [&circ, &sine](jack_default_audio_sample_t* inBuf,
      jack_default_audio_sample_t* outBuf, jack_nframes_t nframes) {

#endif
    for(unsigned int i = 0; i < nframes; i++) {
        float sample = sine.genNextSample();
        outBuf[i] = (sample + circ.process(sample)) * 0.5;


#if WRITE_TO_FILE
    // ---------------------------
    // FOR WRITING TO PYTHON
    // ---------------------------
        static int count = 0;
        if(count < WRITE_NUM_SAMPLES) {
          fileWriter.write(std::to_string(outBuf[i]) + "\n");
        } else {

          // log 'Done' message to console, only once
          static bool loggedDone = false;
          if(!loggedDone) {
            std::cout << "\n**** DONE **** \n"
              << "Output is written to file.\n"
              << "Please enter 'q' to quit the program." << std::endl;
            loggedDone = true;
          }
        }
        count++;
        // set output to 0 to prevent issues with output
        outBuf[i] = 0;
  #endif
      }
      return 0;
    };
    jack.autoConnect();
    //keep the program running and listen for user input, q = quit
    std::cout << "\n\nPress 'q' when you want to quit the program.\n";
    // boolean is used to keep program running / turn it off
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



