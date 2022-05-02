#include "freeze.h"

Freeze::Freeze(){
}

Freeze::~Freeze(){
    // delete delay1;
    // delay1 = nullptr;
}

void Freeze::processEffect(float &input, float &output){

    // delay1.setInput(input);
    output = delay1->getVal(input);
    std::cout << delay1->getVal(input) << std::endl;
    

    
    
    // REVERSED BUFFER
    // buffer[size - i - 1]
}