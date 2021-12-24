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
    // std::string waveForms[2] = {"sine","sine"};
    // float freqs[3] = {80,500,80};    
    // float mod_index[3] = {10,100,20};
    float amplitude = 0.2;

    FM_synth fm1;

    // initialize FM synth with 
    // carwaveform, modwaveform, midipitch, ratioModulator, modIndex
    // (advised ratio = not higher then 6)
    // (advised modIndex = weird sound , higher then 100, nice sounds lower then 100)    
    fm1.initialize("sine","sine",20,10,1);
    fm1.setPitch(40);





    Wavetable wave;
    std::string waveForms[3] = {"sine","sine","square"};
    int midiPitches[4] = {40,48,45,33};

    wave.initialize(waveForms,midiPitches,NUMBER_OSCILLATORS);
    wave.setPitch(60,0);

    fm1.write_waveform();



    float ratio[4] = {1.2,0.2,0.5,1};
    int nieuw = 0;
    int framecount = 0;
    int interval = 44100;

    JackModule jack;
    jack.init(argv[0]);
    jack.onProcess = [&fm1, &amplitude, &ratio, &nieuw, &framecount, &interval, &midiPitches]
    (jack_default_audio_sample_t *inBuf, jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
        for(unsigned int i = 0; i < nframes; i++) {
            outBuf[i] = fm1.nextSample() * amplitude;
            framecount++;
            if (framecount > interval){
                std::cout << "pitch : ";
                framecount = 0;
                nieuw++;
                if (nieuw >= 4){
                    nieuw = 0; 
                }
                float newratio = ratio[nieuw]; 
                float newpitch = midiPitches[nieuw];
                fm1.setRatio(newratio);
                fm1.setPitch(newpitch);

                std::cout << newratio << std::endl;
                std::cout << newpitch << std::endl;


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

