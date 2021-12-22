#include "wavetable.h"

#define SAMPLERATE 44100

Wavetable::Wavetable() : Synth(){
}

Wavetable::~Wavetable(){
}

void Wavetable::initialize(std::string waveform[],int midiPitches[],int input_number_oscs){
    for (int i = 0; i < number_oscs; i++){
        if (waveform[i] == "sine"){
            oscillator[i] = new Sine;
        }
        else if (waveform[i] == "saw"){
            oscillator[i] = new Saw;
        }
        else if (waveform[i] == "square"){
            oscillator[i] = new Square;
        }

    oscillator[i]->initialize(1,SAMPLERATE);
    setMidiPitch(midiPitches[i],i);
    }
}

void Wavetable::updateOscFreq(int pitch,int oscillator_number){
    oscillator[oscillator_number]->setFrequency(pitch);   
}

float Wavetable::getFrequency(int oscillator_number){
    float freq = oscillator[oscillator_number]->getFrequency();
    return freq;
    
}

float Wavetable::nextSample(){ 
    float total = 1;
    for (int i = 0; i < number_oscs; i++){ 
        total = total * oscillator[i]->getSample(); 
        oscillator[i]->tick();
    }
    
    sample = (pow(2,total)) - 1;
    return sample;
}







