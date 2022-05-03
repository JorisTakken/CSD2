#include "freeze.h"

Freeze::Freeze(){
    delay1->setDrywet(1);
}

Freeze::~Freeze(){
    delete delay1;
    delay1 = nullptr;
    delete delay2;
    delay2 = nullptr;
    delete delay3;
    delay3 = nullptr;
    delete delay4;
    delay4 = nullptr;
}

void Freeze::applyEffect(float &input, float &output){
    delay1->applyEffect(input,output);
    delay2->applyEffect(input,output);
    delay3->applyEffect(input,output);
    delay4->applyEffect(input,output);





    
    
    // REVERSED BUFFER
    // buffer[size - i - 1]
}