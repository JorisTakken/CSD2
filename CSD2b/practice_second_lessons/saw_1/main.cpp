#include <iostream>
#include "saw.h"
#include "writeToFile.h"



int main(){  
    Saw saw("saw",100,0.5, SAMPLERATE);

    WriteToFile saw_file("saw_values.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {
    saw_file.write(std::to_string(saw.getSample()) + "\n");
    saw.tick(i);
    }

}
