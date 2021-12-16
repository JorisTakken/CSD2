#include <iostream>
#include "wavetable.h"

#define SAMPLERATE 44100

Wavetable::Wavetable(
    std::string wave_1,
    float freqWave_1,
    std::string wave_2,
    float freqWave_2,
    float amplitude,
    float ratio)
    : 
    Synth(wave_1, freqWave_1, wave_2, freqWave_2, amplitude,ratio){
}

Wavetable::~Wavetable(){
}

void Wavetable::calculate(){
    tick();
}





void Wavetable::write_waveform(){   
    WriteToFile file("1_fm_waveForm.csv", true);
    initialize();
    for(int i = 0; i < SAMPLERATE; i++) {
        car_and_mod = (pow(2,modulator->getSample() * carrier->getSample())) - 1;
        file.write(std::to_string(car_and_mod) + "\n");
        tick();
    }
}



// //heb zelf geen ADSR dr in maar een statische waarde _ experimenteer dr mee, kijk wat voor boventonen je krijgt ;) 
// ModulationIndex = (ratio * Frequency) * ADSR 
// modulatorFreq = Frequency * Ratio
// carrierFreq = Frequency + (outputModulator * Modulation Index)

