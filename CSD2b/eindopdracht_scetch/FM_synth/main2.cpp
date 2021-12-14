#include <iostream>
#include <thread>
#include "sine.h"
#include "saw.h"
#include "fm_synth.h"
#include "ring_mod_synth.h"
#include "synthesizer.h"
#include "jack_module.h"

#define SAMPLERATE 44100

int main(int argc,char **argv){
    std::string modWave = "square"; 
    std::string carWave = "saw";

    RING_synth ring(carWave + "C", 100, modWave + "M",1000,1);
    ring.write_waveform();
   
    // int framecount = 0; 
    // int interval = 0; 

    JackModule jack;
    jack.init(argv[0]);
    jack.onProcess = [&ring](jack_default_audio_sample_t *inBuf,
        jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
        for(unsigned int i = 0; i < nframes; i++) {
            outBuf[i] = ring.getSample();
            ring.calculate();
            // if (framecount > interval){
            //     std::cout << "niewe pitch" << "/n";
            // }
            // framecount += framecount;
            // std::cout << framecount << "/n";
            

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

















    // int number_oscilators = 10;
    // float freq_bigOsc[number_oscilators] = [100,120,150,600,500,400,420,1000,70,500]
    // float waveform_list[number_oscilators] = ["sine","sine","saw","sine","saw","sine","sine","saw","sine","saw"]
    // Multible_osc bigOsc(number_oscilators,freq_bigOsc,waveform_list, 0.5);



