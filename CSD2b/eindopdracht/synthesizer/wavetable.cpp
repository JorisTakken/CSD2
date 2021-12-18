#include "wavetable.h"

#define SAMPLERATE 44100

Wavetable::Wavetable(){
}

Wavetable::~Wavetable(){
}

void Wavetable::validate_numOscillators(int input_number_oscs){
    bool rightInput = true;
    while (rightInput){
        if (input_number_oscs < MAX_OSCILLATORS){
            this->number_oscs = input_number_oscs;
            std::cout << "number of oscillators : " << input_number_oscs << std::endl;
            rightInput = false;
        }else{
        std::cout << "put a number of oscillators between 0 and 20, 20 is the max!" << std::endl;
        std::cout << MAX_OSCILLATORS << std::endl;
        
        std::cin >> input_number_oscs;
        std::cout << " " << std::endl;
        }
    }
}

void Wavetable::initialize(std::string waveform[],float frequencys[],int input_number_oscs){
    validate_numOscillators(input_number_oscs);

    
      
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

float Wavetable::getFrequency(int oscillator_number){
    float freq = oscillator[oscillator_number]->getFrequency();
    return freq;
}



void Wavetable::calculate(){ 
    float total = 1;
    for (int i = 0; i < number_oscs; i++){ 
        total = total * oscillator[i]->getSample(); 
    }
    sample = (pow(2,total)) - 1;
    for (int i = 0; i < number_oscs; i++){ 
        oscillator[i]->tick();
    }
}

float Wavetable::getSample(){
    return sample;
}



void Wavetable::write_waveform(){   
    WriteToFile file("1_fm_waveForm.csv", true);
    for(int i = 0; i < SAMPLERATE; i++) {
        float total = 1;
        for (int i = 0; i < number_oscs; i++){ 
            total = total * oscillator[i]->getSample(); 
        }

        float samp = (pow(2,total)) - 1;
        file.write(std::to_string(samp) + "\n");
        for (int i = 0; i < number_oscs; i++){ 
            oscillator[i]->tick();
        }  
    }
}
    




// //heb zelf geen ADSR dr in maar een statische waarde _ experimenteer dr mee, kijk wat voor boventonen je krijgt ;) 
// ModulationIndex = (ratio * Frequency) * ADSR 
// modulatorFreq = Frequency * Ratio
// carrierFreq = Frequency + (outputModulator * Modulation Index)

