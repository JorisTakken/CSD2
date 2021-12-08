#include <iostream>
#include <thread>
#include "sine.h"
#include "square.h"
#include "jack_module.h"
#include "writeToFile.h"



int main(int argc,char **argv){
  JackModule jack;
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

    Square square("sine",200, 0.5, samplerate); 


   WriteToFile square_file("square_values.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {
    square_file.write(std::to_string(square.getSample()) + "\n");
    square.tick();
    }
} 

