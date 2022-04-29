#include "freeze.h"

Freeze::Freeze(){

}

Freeze::~Freeze(){
    delete delay1;
    delay1 = nullptr;

}

void Freeze::processEffect(float &input, float &output){
    delay1.setDrywet(1);    
    delay1.processEffect(input,output);

}