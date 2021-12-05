#include <iostream>
#include "oscillator.h"




Oscillator::Oscillator(std::string waveform, float frequency, float amplitude, int samplerate) : 
    waveform(waveform), frequency(frequency), amplitude(amplitude), samplerate(samplerate){
}

Oscillator::~Oscillator(){

}

void Oscillator::changeWaveform(std::string waveform){

}

void Oscillator::playWaveform(){
}


void Oscillator::makeListOfPoints(){
    WriteToFile sine_file("sine_values.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {
    sine_file.write(std::to_string(sine.getSample()) + "\n");
    sine.tick();
    }

    WriteToFile square_file("square_values.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {
    square_file.write(std::to_string(square.getSample()) + "\n");
    square.tick();
    }

}