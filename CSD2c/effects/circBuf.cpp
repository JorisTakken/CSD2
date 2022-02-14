#include "circBuf.h"


circBuf::circBuf(int size, int numSamplesDelay) : Effect(samplerate),
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

circBuf::~circBuf(){
    delete [] buffer;
    buffer = nullptr;
}

float circBuf::process(float inputSample){
    buffer[writePoint++] = inputSample;
    writePoint = wrap(writePoint);

    float readVal = buffer[readPoint++];
    readPoint = wrap(readPoint);
    return readVal;
}



float circBuf::getDistance(){   
    if(writePoint < readPoint) {
        int flip = writePoint;
        flip += size;
        return flip - readPoint;
    }
    return writePoint - readPoint;
}


float circBuf::wrap(int point){
    if (point >= size){
        point -= size; 
    }

    return point;
}