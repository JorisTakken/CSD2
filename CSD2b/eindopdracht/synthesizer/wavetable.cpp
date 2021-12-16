#include <iostream>
#include "wavetable.h"
#include "1_writeToFile.h"


#include "sine.h"
#include "saw.h"
#include "square.h"

#include "math.h"


#define SAMPLERATE 44100

Wavetable::Wavetable(){
}

Wavetable::~Wavetable(){
}


void Wavetable::initialize(std::string waveform[],float frequencys[],int number_oscs){
    
    this->number_oscs = number_oscs;
    for (int i = 0; i < number_oscs; i++){
        if (waveform[i] == "sineC"){
        oscillator[i] = new Sine();
    }
    else if (waveform[i] == "sawC"){
        oscillator[i] = new Saw();
    }
    else if (waveform[i] == "squareC"){
        oscillator[i] = new Square();
    }
    oscillator[i]->initialize(frequencys[i],1,SAMPLERATE);
    }
}


void Wavetable::calculate(){ 
    for (int i = 0; i < number_oscs; i++){ 
        oscillator[i]->tick();
}
}

void Wavetable::write_waveform(){   
    float total;
    WriteToFile file("1_fm_waveForm.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {
        for (int i = 0; i < number_oscs; i++){ 
            total *= oscillator[i]->getSample();
            samp = (pow(2,total)) - 1;
            file.write(std::to_string(samp) + "\n");
            oscillator[i]->getSample();
        }
    
}



// //heb zelf geen ADSR dr in maar een statische waarde _ experimenteer dr mee, kijk wat voor boventonen je krijgt ;) 
// ModulationIndex = (ratio * Frequency) * ADSR 
// modulatorFreq = Frequency * Ratio
// carrierFreq = Frequency + (outputModulator * Modulation Index)

