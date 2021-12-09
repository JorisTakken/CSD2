#include <iostream>
#include <thread>
#include "sine.h"
#include "saw.h"
#include "fm_synth.h"
#include "jack_module.h"

#define SAMPLERATE 44100

int main(int argc,char **argv){
    JackModule jack;
    jack.init(argv[0]);

    FM_synth fm1(200,100,SAMPLERATE);

    // float buffer = fm1.make_wave();
    // fm1.write_wave();

    // float amplitude = 0.1;

    jack.onProcess = [&fm1](jack_default_audio_sample_t *inBuf,
        jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

        for(unsigned int i = 0; i < nframes; i++) {
        fm1.make_wave();
        }
        return 0;
    };
    jack.autoConnect();
    std::cout << "\n\nPress 'q' when you want to quit the pmrogram.\n";
    bool running = true;
    while (running)
    {
        switch (std::cin.get())
        {
        case 'q':
            running = false;
            jack.end();
            break;
        }
    }
    //end the program
    return 0;
} 




