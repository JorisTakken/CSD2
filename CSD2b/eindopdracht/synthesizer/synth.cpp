#include "synth.h"

#define SAMPLERATE 44100

Synth::Synth(){
}

Synth::~Synth(){
}

void Synth::setMidiPitch(int midiPitch){
    this->midiPitch = midiPitch;
    float pitch = mtof(midiPitch);
    updateOscFreq(pitch);
}

float Synth::getMidiPitch(){
    return midiPitch;
}

float Synth::mtof(int midiPitch){
   //https://www.music.mcgill.ca/~gary/307/week1/node28.html
   return 440.0 * pow(2.0, ((midiPitch-57.0)/12.0));
}
