#include <iostream>
#include <thread>
#include "sine.h"
#include "jack_module.h"
#include "ui_input.h"
#include "melody.h"

#include "1_writeToFile.h"
#include "wavetable.h"
#include "fm_synth.h"

#define NUMBER_PITCHES 12
#define SAMPLERATE 44100


#define NUMBER_OSCILLATORS 3

#define MIN_FREQ_WAVETABLE 2
#define MAX_FREQ_WAVETABLE 10000

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */






// TODO: 
// UI:  
    // choose your synth : 
        // (fm) (wavetable)

    // do you want to hear 1 tone or a melodie?
        // (melo) (note)



// wavetable: NOTE
// if (melodie or not = note){
    // if (choise = wavetable) {
        // how many oscillator woulkd you like to modulate each other :
            // (Number_oscillators)
        // choose waveforms yourself or all waveforms are sines saws or squares?
            // (my choise) (sines) (saws) (squares)
        // choose midiPitches myself or (random/preset)
            // (my choise) (preset) (random)    
    // }
// }

// wavetable: MELODY

// if (melodie or not = melodie){
    // if (choise = wavetable) {
        // how many oscillator woulkd you like to modulate each other :
            // (Number_oscillators)
        // choose waveforms yourself or all waveforms are sines saws or squares?
            // (my choise) (sines) (saws) (squares)
        // welke toonladder would you like your generated melody?
            // (C7) (Dm7) (G) (Fmin)    
    // }
// }
   


 


int main(int argc,char **argv){


    Melody melo;
    
    melo.setScale(); 
    melo.setMelodyType();


    float amplitude = 0.2;
    Wavetable wave1;

    // initialise wavetable, give waveform and pitch for every oscilator
    std::string waveForms[3] = {"sine","sine","sine"};
    int midipitches[3] = {20,64,57};
    wave1.initialize(waveForms,midipitches,NUMBER_OSCILLATORS);
    wave1.write_waveform();



    int framecount = 0;
    int interval = 44100;
    int nieuw = 1;
    int lenght = 0;


    JackModule jack;
    jack.init(argv[0]);
    jack.onProcess = [&wave1, &melo, &amplitude, &framecount, &interval, &nieuw, &lenght]
    (jack_default_audio_sample_t *inBuf, jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
        for(unsigned int i = 0; i < nframes; i++) {
            outBuf[i] = wave1.nextSample() * amplitude;
            framecount++;
            if (framecount > interval){
                lenght = 1;
                melo.setNotelenght(lenght);
                interval = (melo.getNotelenght() / 4);
                
                
                nieuw++;
                if (nieuw == 7){
                    nieuw = 0;
                }
                wave1.setPitch(melo.liniair(nieuw), 0);

                framecount = 0;
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




//int Wavetable::UI_midiPitches(int osc){
//     User_input user_wavetable_freq;   
//     int midinote;
//         std::cout << "=======================================" << std::endl;
//         std::cout << "choose Frequency for wave number : "  << osc << std::endl;
//         std::cout << "freqcuency should be a frequency between" <<  0 <<  " and "  << 127 << std::endl;
//         midinote = user_wavetable_freq.user_input_numbers(0,127);
//         std::cout << "You selected: " << midinotes << std::endl;
//         std::cout << "=======================================" << std::endl;
//     return midinote;
// }  
    