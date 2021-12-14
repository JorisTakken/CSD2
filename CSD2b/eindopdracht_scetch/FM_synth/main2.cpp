#include <iostream>
#include <thread>
#include "sine.h"
#include "saw.h"
#include "fm_synth.h"
#include "ring_mod_synth.h"
#include "synthesizer.h"
#include "jack_module.h"


#define NUMBER_PITCHES 12
#define SAMPLERATE 44100






int main(int argc,char **argv){
    // std::cout << "doet het" << std::endl;

    std::string modWave = "saw"; 
    std::string carWave = "saw";

    FM_synth ring(carWave + "C", 901, modWave + "M",100,1);
    ring.write_waveform();
    std::cout << "doet het2" << std::endl;
    
    ring.setFrequency_carrier(100);
    // int pitch = 0;
    int framecount = 0;
    int interval = 22100; 
    int nieuw = 0;
    float pitches[NUMBER_PITCHES] = {100,120,150,170,180,200,240,250,270,300,320,340};
    // float pitch;

    JackModule jack;
    jack.init(argv[0]);
    jack.onProcess = [&ring, &framecount, &interval, &pitches, &nieuw]
    (jack_default_audio_sample_t *inBuf,jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
        for(unsigned int i = 0; i < nframes; i++) {
            outBuf[i] = ring.getSample();
            ring.calculate();
            framecount++;

            if (framecount > interval){
            std::cout << "pitch" << std::endl;
                framecount = 0;
                nieuw++;
                if (nieuw > NUMBER_PITCHES - 1){
                    nieuw = 0;
            }
                std::cout << pitches[nieuw] << std::endl;
                
                
            
                
                // pitch = pitches[nieuw];
                // std::cout << pitch << std::endl;

            //     // ring.setFrequency_carrier(pitch);
            //     // ring.getFrequency_carrier();
            //     framecount = 0;
            //     }
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



// int melody(int note){
    
// }






    // int number_oscilators = 10;
    // float freq_bigOsc[number_oscilators] = [100,120,150,600,500,400,420,1000,70,500]
    // float waveform_list[number_oscilators] = ["sine","sine","saw","sine","saw","sine","sine","saw","sine","saw"]
    // Multible_osc bigOsc(number_oscilators,freq_bigOsc,waveform_list, 0.5);



