#include "synth.h"

#define SAMPLERATE 44100

Synth::Synth(){
}

Synth::~Synth(){
}

//------------------------------------------------------------------
// set midipitch whitch converts midi pitch to useble frequencie
// number oscillator is for Wavetable 
// you can choose to set midipitch for 1 oscillator of wavetable
// this function imidiatly pushes frequencie to oscillator
//------------------------------------------------------------------
void Synth::setMidiPitch(int midiPitch,int oscillator_number){
    this->midiPitch = midiPitch;
    float pitch = mtof(midiPitch);
    updateOscFreq(pitch,oscillator_number);
}

float Synth::getMidiPitch(){
    return midiPitch;
}

float Synth::mtof(int midiPitch){
// formula for converting midipitch to ferquencie
//https://www.music.mcgill.ca/~gary/307/week1/node28.html
   return 440.0 * pow(2.0, ((midiPitch-57.0)/12.0));
}
