#include <iostream>
#include "fm_synth.h"

#define SAMPLERATE 44100

FM_synth::FM_synth(
    std::string wave_1,
    float freqWave_1,
    std::string wave_2,
    float freqWave_2,
    float amplitude,
    float ratio) 
    : 
    Synth(wave_1, freqWave_1, wave_2, freqWave_2, amplitude, ratio){
}

FM_synth::~FM_synth(){
    delete carrier;
    carrier = nullptr;
    delete modulator;
    modulator = nullptr;
}

void FM_synth::initialize(){
    if (wave_1 == "sineC"){
        carrier = new Sine();
    }
    else if (wave_1 == "sawC"){
        carrier = new Saw();
    }
    else if (wave_1 == "squareC"){
        carrier = new Square();

    }
    if (wave_2  == "sineM"){
        modulator = new Sine();;
    }
    else if (wave_2 == "sawM"){
        modulator = new Saw();
    }
    else if (wave_2 == "squareM"){
        modulator = new Square();
    }
    modulator->initialize(waveFreq_1 * ratio,amplitude,SAMPLERATE);
    carrier->initialize(waveFreq_2,amplitude,SAMPLERATE);
}



void FM_synth::calculate(){
    tick();
}



void FM_synth::write_waveform(){   
    WriteToFile file("1_fm_waveForm.csv", true);
    initialize();
    for(int i = 0; i < SAMPLERATE; i++) {
        wave = (carrier->getSample() + modulator->getSample()) / 2;
        file.write(std::to_string(wave) + "\n");
        tick();
    }
}


// ModulationIndex = (ratio * Frequency) * ADSR //heb zelf geen ADSR dr in maar een statische waarde _ experimenteer dr mee, kijk wat voor boventonen je krijgt ;) 
// modulatorFreq = Frequency * Ratio
// carrierFreq = Frequency + (outputModulator * Modulation Index)
