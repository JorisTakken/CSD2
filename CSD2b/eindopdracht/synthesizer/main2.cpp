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



int main(int argc,char **argv){
    // std::string waveFormOptions[3] = {"sine", "saw", "square"};
    // int numWaveFormOptions = 3;
    // User_input user;
    // std::string waveform_selected = user.make_userSelection(waveFormOptions,numWaveFormOptions);
    // std::cout << "You selected: " << waveform_selected << std::endl;

    std::string waveforms[NUMBER_OSCILLATORS] = {"sine","sine","saw","square"};
    float freqs[NUMBER_OSCILLATORS] = {100,200,4,1000};

    Wavetable wave;
    wave.initialize(waveforms,freqs,NUMBER_OSCILLATORS);
    wave.write_waveform(); 
    std::cout << "doet?????" << std::endl;





    // wave.setFrequency(100,0);
    // wave.getFrequency();



    
    JackModule jack;
    jack.init(argv[0]);
    jack.onProcess = [&wave]
    (jack_default_audio_sample_t *inBuf,
        jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
        for(unsigned int i = 0; i < nframes; i++) {
            outBuf[i] = wave.getSample();
            wave.calculate();
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

