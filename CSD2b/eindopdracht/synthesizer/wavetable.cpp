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
            oscillator[i] = new Sine;
        }
        else if (waveform[i] == "saw"){
            oscillator[i] = new Saw;
        }
        else if (waveform[i] == "square"){
            oscillator[i] = new Square;
        }

    oscillator[i]->initialize(frequencys[i],1,SAMPLERATE);
    }
}

void Wavetable::setFrequency(float newFreq,int oscillator_number){
    oscillator[oscillator_number]->setFrequency(newFreq);   
}

float Wavetable::getFrequency(){
    float freq = oscillator[oscillator_number]->getFrequency();
    return freq;
}



void Wavetable::calculate(){ 
    float total = 1;
    for (int i = 0; i < number_oscs; i++){ 
        total = total * oscillator[i]->getSample(); 
        oscillator[i]->tick();
    }
    sample = (pow(2,total)) - 1;

}

float Wavetable::getSample(){
    return sample;
}



void Wavetable::write_waveform(){   
    // float samples;

        
    WriteToFile file("1_fm_waveForm.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {
            float total = 1;
            for (int i = 0; i < number_oscs; i++){ 
                total = total * oscillator[i]->getSample(); 
                oscillator[i]->tick();
            }

            float samp = (pow(2,total)) - 1;
            file.write(std::to_string(samp) + "\n");
                
            }
        }
    




// //heb zelf geen ADSR dr in maar een statische waarde _ experimenteer dr mee, kijk wat voor boventonen je krijgt ;) 
// ModulationIndex = (ratio * Frequency) * ADSR 
// modulatorFreq = Frequency * Ratio
// carrierFreq = Frequency + (outputModulator * Modulation Index)

