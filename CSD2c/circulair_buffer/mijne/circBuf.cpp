#include "circBuf.h"
#include <iostream>

circBuf::circBuf(int size, int numSamplesDelay) : 
    size(size), numSamplesDelay(numSamplesDelay),
    writePoint(0), readPoint(0){
    buffer = new float[size];
}

circBuf::~circBuf(){
}

void circBuf::addValue(float newValue){
    buffer[writePoint++] = newValue;
    writePoint = wrap(writePoint);


    // int input;
    // for (int i = 0; i < size; i++){
    //     std::cin >> input;
    //     std::cout << input;
    //     buffer[i] = input;
    // }
    
}

float circBuf::readValue(){
    // return buffer[i - numSamplesDelay]
    
}

float circBuf::wrap(int point){
    if (point >= size){
        point = 0; 
    }
    return point;
}