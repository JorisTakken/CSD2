#include "delay.h"


Delay::Delay(int size, int numSamplesDelay) :
    size(size), numSamplesDelay(numSamplesDelay),
    writePoint(0), readPoint(size - numSamplesDelay){

    while (numSamplesDelay > size) {
        std::cout << "MAG NIET, kies andere sampledelay!" << std::endl;
        std::cout << "kies maar : " << std::endl;
        int input;
        std::cin >> input;
        numSamplesDelay = input;
    }
    buffer = new float[size];
    for(int i = 0; i < size; i++) {
        buffer[i] = 0;
    }
}

Delay::~Delay(){
    delete [] buffer;
    buffer = nullptr;
}

float Delay::processEffect(float inputSample){
    buffer[writePoint++] = inputSample;
    writePoint = wrap(writePoint);

    float readVal = buffer[readPoint++];
    readPoint = wrap(readPoint);
    return readVal;
}



float Delay::getDistance(){   
    if(writePoint < readPoint) {
        int flip = writePoint;
        flip += size;
        return flip - readPoint;
    }
    return writePoint - readPoint;
}


float Delay::wrap(int point){
    if (point >= size){
        point -= size; 
    }

    return point;
}