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

#define WRITE_TO_FILE 0

#define NUMBER_OSCILLATORS 2

#define MIN_FREQ_WAVETABLE 2
#define MAX_FREQ_WAVETABLE 10000

std::string chooseSynth(Synth* &synth,Synth* fmSynth,Synth* wavetable){
    User_input synthSel;
    std::cout << "==============================================" << std::endl;
    std::cout << "choose your synth : FM (fm) wavetable (w)" << std::endl;
    std::string synthChoises[2] = {"fm","w"};
    std::string synthChoise = synthSel.make_userSelection(synthChoises,2);
    std::cout << "synthChoise " << synthChoise << std::endl;
    std::cout << "==============================================" << std::endl;
    if (synthChoise == "fm"){
        synth = fmSynth;
    }
    else if (synthChoise == "w"){
        synth = wavetable;
    }
    return synthChoise;
}

int main(int argc,char **argv){
    Synth* synth = nullptr;
    FM_synth fmSynth;
    Wavetable wavetable;    

    std::string synthChoise = chooseSynth(synth,&fmSynth,&wavetable);
    // std::cout << chooseSynth(synth,&fmSynth,&wavetable) << std::endl;

    if (synthChoise == "fm"){
            // ------------------------------------------------------------------
            // initialise FM synth, give waveform and pitch for every oscilator.
        User_input FM;
            std::string waveOptions[3] = {"saw","sine","square"};
            std::cout << "choose waveform carrier : " << std::endl;
            std::string waveFormCar = FM.make_userSelection(waveOptions, 3);
            std::cout << "choose waveform modulator : " << std::endl;
            std::string waveFormMod = FM.make_userSelection(waveOptions, 3);
            std::cout << "choose ratio : " << std::endl;
            float ratio = FM.user_input_numbers(0,40);
            std::cout << "choose modulaton depth : " << std::endl;
            float modDepth = FM.user_input_numbers(0,1000);
        fmSynth.initialize(waveFormCar,waveFormMod,40,ratio,modDepth);
         // ------------------------------------------------------------------           
    } else if (synthChoise == "w"){
        // ------------------------------------------------------------------
        // initialise wavetable, give waveform and pitch for every oscilator
        // std::string waveForms[NUMBER_OSCILLATORS] = {"square","sine"};
        // ------------------------------------------------------------------

        User_input waveUI;
            std::string waveOptions[3] = {"saw","sine","square"};
            std::string waveforms[NUMBER_OSCILLATORS];
            int midipitches[NUMBER_OSCILLATORS];    
                for (int i = 0; i < NUMBER_OSCILLATORS; i++){
                    std::cout << "choose waveform for oscillator number : " << i + 1 <<  std::endl;
                    waveforms[i] = waveUI.make_userSelection(waveOptions,3);
                    std::cout << "choose midipitch for oscillator number : " << i + 1 <<  std::endl;
                    midipitches[i] = waveUI.user_input_numbers(0,127);
                }
        wavetable.initialize(waveforms,midipitches,NUMBER_OSCILLATORS);
        // ------------------------------------------------------------------

    }
    
    Melody melo;
    melo.setScale(); 
    melo.setMelodyType();
    
#if WRITE_TO_FILE
    WriteToFile fileWriter("_waveForm.csv", true);

if(synth != nullptr) {
  // hier je forloop 
    std::cout << "nullptr"<< std::endl;
    for(int i = 0; i < SAMPLERATE; i++) {
        fileWriter.write(std::to_string(synth->nextSample()) + "\n");
    }

}
    
#else

    float amplitude = 0.2;
    int framecount = 0;
    int interval = 44100;
    int nieuw = 1;
    int lenght = 0;

    JackModule jack;
    jack.init(argv[0]);
    jack.onProcess = [&synth, &melo, &amplitude, &framecount, &interval, &lenght, &nieuw, &synthChoise]
    (jack_default_audio_sample_t *inBuf, jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
        for(unsigned int i = 0; i < nframes; i++) {
            
                outBuf[i] = synth->nextSample() * amplitude;
                if (synthChoise == "fm"){
                framecount++;
                if (framecount > interval){
                        lenght++;
                        if (lenght == 10){
                            lenght = 0;
                        }
                        melo.setNotelenght(lenght);
                        interval = (melo.getNotelenght());
                        nieuw++;
                        if (nieuw == 8){
                            nieuw = 0;
                        }
                        std::cout << melo.liniair(nieuw) << std::endl;
                        synth->setMidiPitch(melo.liniair(nieuw) - 4,0);
                        framecount = 0;

            }else if(synthChoise == "m"){
                }   
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
#endif
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
    