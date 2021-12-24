#include <iostream>
#include <thread>
#include "sine.h"
#include "jack_module.h"
#include "ui_input.h"
#include "1_writeToFile.h"
#include "wavetable.h"

#define NUMBER_PITCHES 12
#define SAMPLERATE 44100


#define NUMBER_OSCILLATORS 4

#define MIN_FREQ_WAVETABLE 2
#define MAX_FREQ_WAVETABLE 10000

// float ui_freq_wavetable(float frequency_selected){
//     User_input user_wavetable_freq;
//     for (int i = 0; i < NUMBER_OSCILLATORS; i++){
//         std::cout << "choose Frequency for wave number :" << i << std::endl;
//         std::cout << " " << std::endl;
//         std::cout << "freqcuency should be a frequency between 2 and 10000" << i + 1 << std::endl;
//         frequency_selected[i] = user_wavetable_freq.user_input_numbers(MIN_FREQ_WAVETABLE,MAX_FREQ_WAVETABLE);
//         std::cout << "You selected: " << frequency_selected[i] << std::endl;

//     }
//     std::cout << "You selected: " << frequency_selected << std::endl;

//     return frequency_selected;
// }




int main(int argc,char **argv){
    User_input user_wavetable_freq;
    float frequency_selected[NUMBER_OSCILLATORS] = {};
    for (int i = 0; i < NUMBER_OSCILLATORS; i++){
        std::cout << "choose Frequency for wave number :" << i << std::endl;
        std::cout << " " << std::endl;
        std::cout << "freqcuency should be a frequency between" <<  MIN_FREQ_WAVETABLE <<  " and "  << MAX_FREQ_WAVETABLE << i + 1 << std::endl;
        frequency_selected[i] = user_wavetable_freq.user_input_numbers(MIN_FREQ_WAVETABLE,MAX_FREQ_WAVETABLE);
        std::cout << "You selected: " << frequency_selected[i] << std::endl;
    }   
    std::cout << "Array " << frequency_selected << std::endl;

    std::string waveFormOptions[NUMBER_OSCILLATORS] = {"sine", "saw","saw","square"};

    float amplitude = 0.5;

    Wavetable wave;
    wave.initialize(waveFormOptions,frequency_selected,NUMBER_OSCILLATORS);
    wave.write_waveform();
    

    int framecount = 0;
    int interval = 44100;
    int nieuw = 0;
    float pitches[NUMBER_PITCHES] = {100,200,300,400,500,600,700,800,900,1000,1100,1200};

    JackModule jack;
    jack.init(argv[0]);
    jack.onProcess = [&wave, &amplitude, &framecount, &interval, &nieuw, &pitches]
    (jack_default_audio_sample_t *inBuf,
        jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
        for(unsigned int i = 0; i < nframes; i++) {
            outBuf[i] = wave.getSample() * amplitude;
            wave.calculate();
            framecount++;
            if (framecount > interval){
                std::cout << "pitch" << std::endl;
                framecount = 0;
                nieuw++;
                if (nieuw >= NUMBER_PITCHES){
                    nieuw = 0; 
                }
                float pitch = pitches[nieuw]; 
                wave.setFrequency(pitch,0);

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

