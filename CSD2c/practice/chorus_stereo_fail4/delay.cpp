#include "delay.h"


Delay::Delay(int size, int delayTime, float feedback) : Effect(samplerate),
    size(size), writePoint(0),feedback(feedback){ 
    
    numSamplesDelay = msToSamps(delayTime);
    this->readPoint = size - numSamplesDelay;

    std::cout << numSamplesDelay << "delaySamples" << std::endl;

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

// void Delay::processEffect(float &input, float &output){
//     buffer[writePoint++] = input + (output * feedback);
//     writePoint = wrap(writePoint);
    
//     output = buffer[readPoint++];
//     readPoint = wrap(readPoint);
// }

void Delay::setDelaytime(int newDelayTime){
    readPoint = size - msToSamps(newDelayTime);
}


float Delay::genNextSample(float inputSample){
    buffer[writePoint++] = inputSample + (outputSample * feedback);
    writePoint = wrap(writePoint);
    
    outputSample = buffer[readPoint++];
    readPoint = wrap(readPoint);
    return outputSample;
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