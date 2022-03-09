#include "delay.h"


Delay::Delay(int size, int numSamplesDelay, float feedback) : Effect(),
    size(size), numSamplesDelay(numSamplesDelay),
    writePoint(0), readPoint(0), feedback(feedback){ 
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

void Delay::applyEffect(float& input, float& output){
    buffer[writePoint++] = input;
    writePoint = wrap(writePoint);

    output = buffer[readPoint++];
    readPoint = wrap(readPoint);
}

void Delay::setDelaytime(float newDelaytime){
    readPoint = writePoint - (int)newDelaytime;
}       

float Delay::map(float input, int x1, int x2 , float min, float max){
    // STARTING AT A X VALUE
    float value = (min * (x2 - input) + max * (input - x1)) / (x2 - x1);    
    return value;
}

float Delay::wrap(int point){
    if (point >= size){
        point -= size; 
    }
    return point;
}