#include <iostream>
#include "saw.h"
#include "square.h"
#include "writeToFile.h"



int main(){  
    Saw saw("saw",10,0.5, SAMPLERATE);
    Square square("square",10,0.5, SAMPLERATE);

    WriteToFile saw_file("saw_values.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {
    saw_file.write(std::to_string(saw.getSample()) + "\n");
    saw.tick(i);
    }

    WriteToFile square_file("square_values.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {
        square_file.write(std::to_string(square.getSample()) + "\n");
        square.tick();
    }

}
