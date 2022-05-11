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
    float in = input;
    delay1->applyEffect(in,output1);
    delay2->applyEffect(in,output2);
    delay3->applyEffect(in,output3);
    delay4->applyEffect(in,output4);
    output = (output1 + output2 + output3 + output4) / 4;
    // std::cout << output << std::endl;




    
    
    // REVERSED BUFFER
    // buffer[size - i - 1]
}