#include <iostream>
#include <thread>
#include "sine.h"
#include "saw.h"
#include "fm_synth.h"

#define SAMPLERATE 44100

int main(){
    // TODO uiteindelijk kan je dit kiezen: 
    // FM_synth fm1(waveCarrier, freqCar, waveModulator, freqModulator )

    FM_synth fm1(100,20,0.5);
    fm1.write_fm_waveform();    

}

