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
    float freqs[3] = {200,500,80};
    float ratio[3] = {8,0.5,1.2};
    float mod_index[3] = {2,100,20};
    float amplitude = 0.2;

    FM_synth fm1;
    FM_synth fm2;
    FM_synth fm3;

    fm1.initialize("sine",freqs[0],ratio[0],mod_index[0]);
    fm2.initialize("sine",freqs[1],ratio[1],mod_index[1]);
    fm3.initialize("sine",freqs[2],ratio[2],mod_index[2]);


    fm1.write_waveform();
    
    int framecount = 0;
    int interval = 3300;
    int nieuw = 0;
    float pitches[NUMBER_PITCHES] = {400,200,300,400,500,222,700,800,442,100,1100,244};




    JackModule jack;
    jack.init(argv[0]);
    jack.onProcess = [&fm1, &fm2, &fm3, &amplitude, &framecount, &interval, &nieuw, &pitches]
    (jack_default_audio_sample_t *inBuf, jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
        for(unsigned int i = 0; i < nframes; i++) {
            float samps = (fm3.sound() + fm2.sound() + fm1.sound()) / 3;
            outBuf[i] = samps * amplitude;
            framecount++;
            if (framecount > interval){
                std::cout << "pitch : ";
                framecount = 0;
                nieuw++;
                if (nieuw >= NUMBER_PITCHES){
                    nieuw = 0; 
                }
                float pitch = pitches[nieuw]; 
                fm1.setFrequency(pitch);
                fm2.setFrequency(pitch);
                fm3.setFrequency(pitch * 2);

                std::cout << pitch << std::endl;

            }









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

