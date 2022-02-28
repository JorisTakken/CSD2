#include "chorus.h"


Chorus::Chorus(int size,int samplesDelay, float chorusRate) : Effect(samplerate), 
size(size), chorusRate(chorusRate),samplesDelay(samplesDelay),
 writePoint(0), readPoint(size - samplesDelay){
    while (samplesDelay > size) {
        std::cout << "creash program" << std::endl;
        std::cout << "HELAAS  numSamplesDelay is groter dan size MAG NIET " << std::endl;
    }
    chorusBuffer = new float[size];
    for(int i = 0; i < size; i++) {
        chorusBuffer[i] = 0;
    }

    oscillator = new Sine(chorusRate, samplerate);
    
}

Chorus::~Chorus(){
    delete [] chorusBuffer;
    chorusBuffer = nullptr;

    delete oscillator;
    oscillator = nullptr;

}   

void Chorus::processEffect(float &input, float &output){
    chorusBuffer[writePoint++] = input;
    writePoint = wrap(writePoint);

    output = chorusBuffer[readPoint++];
    readPoint = samplesDelay + inRange(oscillator->genNextSample(), -1, 1, 60, 1000);
    // samplesDelay += (oscillator->genNextSample() * 1000);
    readPoint = wrap(readPoint);
}


float Chorus::wrap(int point){
    if (point >= size){
        point -= size; 
    }
    return point;
}

float Chorus::inRange(float input, int x1, int x2 , float min, float max){
    // STARTING AT A X VALUE
    float value = (min * (x2 - input) + max * (input - x1)) / (x2 - x1);    
    return value;
}