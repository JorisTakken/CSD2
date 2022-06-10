#include <string>
#include <iostream>
#include <math.h>
#include <thread>
#include <unistd.h> // sleep
#include "jack_module.h"
#include "keypress.h"
#include "bufferDebugger.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "Highlights.h"

#define REDMASK	(0xff0000)
#define GREENMASK (0x00ff00)
#define BLUEMASK (0x0000ff)

using namespace cv;
using namespace std;
typedef unsigned int uint;


Highlights detect;


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
    }

    jack.writeSamples(outbuffer,chunksize*2);
  } while(running);
}

int main(int argc, char **argv){
  // -------------------------------
  char command='@';
  // jack.init(argv[0]);
  // jack.autoConnect();
  // jack.setNumberOfInputChannels(2);
  // jack.setNumberOfOutputChannels(2);
  // thread filterThread(audio);
  // -------------------------------

    char* imageName = argv[1];
    Mat image;
    Mat gray_image;

    image = imread( imageName, IMREAD_COLOR );
    detect.binaryImage(image,gray_image);
    imshow("Display window", gray_image);


  while (running) {
    
    waitKey(250);
  }

  while(command != 'q')
  {
    if(keypressed()) {
      command = getchar();
    }
    usleep(100000);
  }

  running=false;
  // filterThread.join();
  // cap.release();

  jack.end();
}

