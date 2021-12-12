#include <iostream>
#include <thread>
#include "sine.h"
#include "saw.h"
#include "LFO.h"
#include "fm_synth.h"
#include "jack_module.h"

// #include <forward_list>


#define SAMPLERATE 44100

int main(int argc,char **argv){
    float amlitude = 0.5;
    // float freq = 99;

    Lfo lfo(1,1,SAMPLERATE);

    
    // float buff;
    // // float *frequ[44100] = {&buff};
    // for(unsigned int i = 0; i < SAMPLERATE; i++) {
    //     buff = (10000 * lfo.getSample());
    //     lfo.tick();
    //     }
    // std::cout << "freq" << buff;

    FM_synth fm1("saw", 200, "sine", 100, amlitude,0.4,2);

    


   
    JackModule jack;
    jack.init(argv[0]);
    jack.onProcess = [&fm1](jack_default_audio_sample_t *inBuf,
        jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
        

        for(unsigned int i = 0; i < nframes; i++) {
            outBuf[i] = fm1.getSample();
            fm1.synth2_tick();
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
    
    fm1.write_fm_waveform_synth2();
    return 0;
} 

















    // int number_oscilators = 10;
    // float freq_bigOsc[number_oscilators] = [100,120,150,600,500,400,420,1000,70,500]
    // float waveform_list[number_oscilators] = ["sine","sine","saw","sine","saw","sine","sine","saw","sine","saw"]
    // Multible_osc bigOsc(number_oscilators,freq_bigOsc,waveform_list, 0.5);



