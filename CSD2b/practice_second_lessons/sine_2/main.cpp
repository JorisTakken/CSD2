#include <iostream>
#include "sine.h"
#include "square.h"
#include "writeToFile.h"

// #define  1




std::string number;


int main(){  
    Sine sine(100.2,0.5);
    Square square(100.2,0.5);


    WriteToFile sine_file("sine_values.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {
    sine_file.write(std::to_string(sine.getSample()) + "\n");
    sine.tick();
    }

    WriteToFile square_file("square_values.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {
    square_file.write(std::to_string(square.getSample()) + "\n");
    square.tick();
    }


}


