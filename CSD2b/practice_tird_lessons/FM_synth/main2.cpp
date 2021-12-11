#include <iostream>
#include <thread>
#include "sine.h"
#include "saw.h"
#include "fm_synth.h"

#define SAMPLERATE 44100

int main()
    FM_synth fm1("saw", 10, "sine",20,0.5);
    FM_synth fm12("sine", 10, "sine",40,0.5);

    fm12.write_fm_waveform();  


}

