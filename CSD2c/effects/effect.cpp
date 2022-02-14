#include "effect.h"

Effect::Effect(unsigned int samplerate){
}

Effect::~Effect(){
}

void Effect::setDrywet(float newDryWet){  
    this->dryWet = newDryWet;
}