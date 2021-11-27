#include <iostream>
#include "oscillator.h"



int main(){
    Oscillator sinus(200.1,0.2); 

    sinus.setFreq(442);
    std::cout << "Freq " << sinus.getFreq() << std:: endl;
}