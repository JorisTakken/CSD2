#include "chorus.h"

#define MAX_SIZE 20000

Chorus::Chorus(int delayMS ,float chorusRate, float chorusDepth) : Effect(44100), 
    delayMS(delayMS), chorusRate(chorusRate), chorusDepth(chorusDepth),
    writePoint(0), readPoint(delayMS){
    
    oscillator = new Sine(chorusRate,samplerate);
    
    chorusBuffer = new float[MAX_SIZE];
    for(int i = 0; i < MAX_SIZE; i++) {
        chorusBuffer[i] = 0;
    }
}

Chorus::~Chorus(){
    delete oscillator;
    oscillator = nullptr;

    delete [] chorusBuffer;
    chorusBuffer = nullptr;
}   

float Chorus::processEffect(float input){
    float modulation = ((oscillator->genNextSample() * chorusDepth) * 1000) + 500;

    chorusBuffer[writePoint++] = input;
    writePoint = wrap(writePoint);
    
    // readPoint =  msToSamps(delayMS) + (int)modulation;
    std::cout << msToSamps(delayMS) + (int)modulation<< "mod" << std::endl;

    float output = chorusBuffer[msToSamps(delayMS) + (int)modulation];
    readPoint = wrap(readPoint);

    return output;
}


float Chorus::wrap(int point){
    if (point >= MAX_SIZE){
        point -= MAX_SIZE; 
    }
    return point;
}

int Chorus::inRange(float input, float x1, float x2 , int min, int max){
    // STARTING AT A X VALUE
    int value = (min * (x2 - input) + max * (input - x1)) / (x2 - x1);  
    return value;
}

int Chorus::msToSamps(float miliseconds){
    return int((miliseconds * (samplerate / 1000.0)) + 0.5);
}

