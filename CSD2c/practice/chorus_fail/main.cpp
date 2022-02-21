#include "tremolo.h"
#include "chorus.h"
#include "delay.h"

#include "writeToFile.h"
#include "jack_module.h"
#include "sine.h"

#define WRITE_TO_FILE 0
#define WRITE_NUM_SAMPLES 44100
#define SAMPLERATE 44100 



int main(int argc,char **argv){
    JackModule jack;
    jack.init(argv[0]);

    // Tremolo trem("sine",2);
    // // dry wet is modDeptht bij mij
    // trem.setDrywet(1);
    
    Sine sine(400,SAMPLERATE);

    Chorus chorus(SAMPLERATE,50, 1);
    Delay delay(44100,20000,0.9);

    Tremolo tremolo(Tremolo::Waveformtype::sine,20);

    delay.setDrywet(0.5,0,1);

#if WRITE_TO_FILE
    WriteToFile fileWriter("output.csv", true);
    // ---------------------------
    // FOR WRITING TO PYTHON
    // ---------------------------
    jack.onProcess = [&delay, &fileWriter, &sine](jack_default_audio_sample_t* inBuf,
      jack_default_audio_sample_t* outBuf, jack_nframes_t nframes) {
  #else
    // ---------------------------
    // FOR JACK AUDIO
    // ---------------------------
    jack.onProcess = [&chorus](jack_default_audio_sample_t* inBuf,
      jack_default_audio_sample_t* outBuf, jack_nframes_t nframes) {

  #endif
      for(unsigned int i = 0; i < nframes; i++) {
        // outBuf[i] = sine.genNextSample() * trem.process();
        chorus.process(inBuf[i],outBuf[i]);
        // outBuf[i] = inBuf[i] * 1;


  #if WRITE_TO_FILE
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



