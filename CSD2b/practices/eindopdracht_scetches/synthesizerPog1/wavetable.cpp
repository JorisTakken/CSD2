#include "wavetable.h"

#define SAMPLERATE 44100

Wavetable::Wavetable() : Synth(){
}

Wavetable::~Wavetable(){
}

// void Wavetable::validate_numOscillators(int input_number_oscs){
//     bool rightInput = true;
//     while (rightInput){
//         if (input_number_oscs < MAX_OSCILLATORS){
//             this->number_oscs = input_number_oscs;
//             std::cout << "number of oscillators : " << input_number_oscs << std::endl;
//             rightInput = false;
//         }else{
//         std::cout << "put a number of oscillators between 0 and 20, 20 is the max!" << std::endl;
//         std::cout << MAX_OSCILLATORS << std::endl;
        
//         std::cin >> input_number_oscs;
//         std::cout << " " << std::endl;
//         }
//     }
// }

void Wavetable::initialize(std::string waveform[],int midiPitches[],int input_number_oscs){
    // validate_numOscillators(input_number_oscs);
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







