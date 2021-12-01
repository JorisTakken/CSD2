#include <iostream>
#include "sine.h"

std::string number;


int main(){  
    Sine sine(100.2,0.5);
    // sine.setFrequency(100.2);
    // sine.setAmplitude(0.2);

    // sine.getFrequency();
    // sine.getAmplitude();

    for(int i = 0; i < 100; i++) {
        number = sine.getSample();
        sine.list_of_values(number);
        sine.tick();
    }
    



}


