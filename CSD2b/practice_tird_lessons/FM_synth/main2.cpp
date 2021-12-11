#include <iostream>
#include <thread>
#include "sine.h"
#include "saw.h"
#include "fm_synth.h"

#define SAMPLERATE 44100

int main(){
    FM_synth fm1("saw", 10, "sine",20,0.5);
    fm1.write_fm_waveform();  

    int number_oscilators = 10;
    float freq_bigOsc[number_oscilators] = [100,120,150,600,500,400,420,1000,70,500]
    float waveform_list[number_oscilators] = ["sine","sine","saw","sine","saw","sine","sine","saw","sine","saw"]


    Multible_osc bigOsc(number_oscilators,freq_bigOsc,waveform_list, 0.5);

}

