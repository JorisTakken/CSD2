#include "wavetable.h"


#define SAMPLERATE 44100

Wavetable::Wavetable(){
}

Wavetable::~Wavetable(){
}

void Wavetable::initialize(std::string waveform[],float frequencys[],int number_oscs){
    this->number_oscs = number_oscs;
    for (int i = 0; i < number_oscs; i++){
        if (waveform[i] == "sine"){
        oscillator[i] = new Sine();
        }
        else if (waveform[i] == "saw"){
            oscillator[i] = new Saw();
        }
        else if (waveform[i] == "square"){
            oscillator[i] = new Square();
        }
    oscillator[i]->initialize(frequencys[i],1,SAMPLERATE);
    }
}


void Wavetable::calculate(){ 
    float total = -1;
    for (int i = 0; i < number_oscs; i++){ 
        oscillator[i]->tick();
        float values = total * oscillator[i]->getSample();
        sample = (pow(2,values)) - 1;
    }
}

float Wavetable::getSample(){
    return sample;
}



void Wavetable::write_waveform(){   
    float total = -1;
    WriteToFile file("1_fm_waveForm.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {
        for (int i = 0; i < number_oscs; i++){ 
            float values = total * oscillator[i]->getSample();
            float samp = (pow(2,values)) - 1;
            file.write(std::to_string(samp) + "\n");
            oscillator[i]->tick();
        }
    }
}



// //heb zelf geen ADSR dr in maar een statische waarde _ experimenteer dr mee, kijk wat voor boventonen je krijgt ;) 
// ModulationIndex = (ratio * Frequency) * ADSR 
// modulatorFreq = Frequency * Ratio
// carrierFreq = Frequency + (outputModulator * Modulation Index)

