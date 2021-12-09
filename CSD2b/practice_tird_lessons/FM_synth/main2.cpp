#include <iostream>
#include <thread>
#include "sine.h"
#include "saw.h"
#include "fm_synth.h"

#define SAMPLERATE 44100

int main(){
    FM_synth fm1(2,20);
    fm1.make_wave();
    fm1.write_wave();
}

