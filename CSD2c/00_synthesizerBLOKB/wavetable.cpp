#include "wavetable.h"

#define SAMPLERATE 44100

Wavetable::Wavetable() : Synth(){
}

Wavetable::~Wavetable(){
    for (int i = 0; i < input_number_oscs; i++){
        delete oscillator[i];
        oscillator[i] = nullptr;
    }
}

// ------------------------------------------------------------------------
// initialize for every oscillator a waveform and a midipitch and say howmany oscillators you want (maximun 20)
// ------------------------------------------------------------------------
void Wavetable::initialize(std::string waveform[],int midiPitches[],int input_number_oscs){
    this->input_number_oscs = input_number_oscs;
    for (int i = 0; i < input_number_oscs; i++){
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

// function goes directly to setfreq of the oscillator 
// choose witch one of the oscillators you want the frequencie to change of.
void Wavetable::updateOscFreq(int pitch,int oscillator_number){    
    oscillator[oscillator_number]->setFrequency(pitch);   
}

float Wavetable::getFrequency(int oscillator_number){
    float freq = oscillator[oscillator_number]->getFrequency();
    return freq;
}

// ------------------------------------------------------------------------
// calculation of the samples of synth
// every sample of every oscillator multiplied en then in to a ^2
// this makes ring_modulation
// ------------------------------------------------------------------------
float Wavetable::nextSample(){ 
    float total = 1;
    for (int i = 0; i < input_number_oscs; i++){ 
        total = total * oscillator[i]->getSample(); 
        oscillator[i]->tick();
    }
    
    sample = (pow(2,total)) - 1;
    return sample;
    
}







