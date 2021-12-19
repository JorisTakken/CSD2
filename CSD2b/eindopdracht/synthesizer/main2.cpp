#include <iostream>
#include <thread>
#include "sine.h"
#include "jack_module.h"
#include "ui_input.h"
#include "1_writeToFile.h"
#include "wavetable.h"
#include "fm_synth.h"






#define NUMBER_PITCHES 12
#define SAMPLERATE 44100


#define NUMBER_OSCILLATORS 2

#define MIN_FREQ_WAVETABLE 2
#define MAX_FREQ_WAVETABLE 10000

int main(int argc,char **argv){
    std::string waveForms[2] = {"sine","sine"};
    float freqs[2] = {150,100};

    FM_synth fm;
    fm.initialize(waveForms,freqs,2);
    fm.write_waveform();



    // JackModule jack;
    // jack.init(argv[0]);
    // jack.onProcess = [&fm, &amplitude]
    // (jack_default_audio_sample_t *inBuf,
    //     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    //     for(unsigned int i = 0; i < nframes; i++) {
    //         outBuf[i] = fm.getSample() * amplitude;
    //         fm.calculate();
    //         }





    //     }
    //     return 0;
    // };

    // jack.autoConnect();
    // std::cout << "\n\nPress 'q' when you want to quit the pmrogram.\n";
    // bool running = true;
    // while (running)
    // {
    //     switch (std::cin.get())
    //     {
    //     case 'q':
    //         running = false;
    //         jack.end();
    //         break;
    //     }
    // }
    // //end the program
    
    
    // return 0;

} 

