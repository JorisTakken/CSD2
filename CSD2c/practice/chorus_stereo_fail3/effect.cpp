#include "effect.h"

Effect::Effect(unsigned int samplerate){
}

Effect::~Effect(){
}
    // pointer to jack audio's in and output buffer
float Effect::applyDryWet(float input){
    // dry wet
    float output = processEffect(input);
    output = output * (dryWet) + input * (1.0 - dryWet);
    return output;
}



void Effect::setDrywet(float newDryWet){  
    float max = 1;
    float min = 0;
    while(newDryWet < 0 ||  newDryWet > 1.0){
        std::cout << "MAG NIET, choose dry wet form 0 - 1!" << std::endl;
        std::cout << "kies maar : " << std::endl;
        int input;
        std::cin >> input;
        newDryWet = input;
    }
    float value;
    float range = max - min; 
    value = range * newDryWet;
    value += min;
    this->dryWet = value;
}

float Effect::getDrywet(){
    return dryWet;
}