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

#define WRITE_TO_FILE 1

#define NUMBER_OSCILLATORS 5

#define MIN_FREQ_WAVETABLE 2
#define MAX_FREQ_WAVETABLE 10000

void chooseSynth(Synth* synth,Synth* fmSynth,Synth* wavetable){
    User_input synthSel;
    std::string synthChoises[2] = {"FM","wavetable"};
    std::string synthChoise = synthSel.make_userSelection(synthChoises,2);
    std::cout << "synthChoise " << synthChoise << std::endl;
    if (synthChoise == "FM"){
        synth = fmSynth;
    }
    if (synthChoise == "wavetable"){
        synth = wavetable;
    }
}

int main(int argc,char **argv){
    Synth* synth = nullptr;
    FM_synth fmSynth;
    // ----------------------
    // initialise FM synth, give waveform and pitch for every oscilator.
    fmSynth.initialize("sine","saw",40,1.2,500);

    Melody melo;
    melo.setScale(); 
    melo.setMelodyType();
// ----------------------
    // ----------------------
    Wavetable wavetable;
    // initialise wavetable, give waveform and pitch for every oscilator
    std::string waveForms[NUMBER_OSCILLATORS] = {"sine","sine","saw","square","sine"};
    int midipitches[NUMBER_OSCILLATORS] = {23,4,23,56,80};    
    wavetable.initialize(waveForms,midipitches,NUMBER_OSCILLATORS);
// ----------------------
  




    chooseSynth(synth,&fmSynth,&wavetable);

   


#if WRITE_TO_FILE
    WriteToFile fileWriter("_waveForm.csv", true);

    for(int i = 0; i < SAMPLERATE; i++) {
        fileWriter.write(std::to_string(synth->nextSample()) + "\n");
    }
#else

    float amplitude = 0.5;
    int framecount = 0;
    int interval = 44100;
    int nieuw = 1;
    int lenght = 0;

    


    JackModule jack;
    jack.init(argv[0]);
    jack.onProcess = [&wave1, &melo, &amplitude, &framecount, &interval, &lenght, &nieuw]
    (jack_default_audio_sample_t *inBuf, jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
        for(unsigned int i = 0; i < nframes; i++) {
            outBuf[i] = wave1.nextSample() * amplitude;
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
                wave1.setMidiPitch(melo.liniair(nieuw) - 4,0);
                wave1.setMidiPitch(melo.liniair(nieuw) - 2,1);
                wave1.setMidiPitch(melo.liniair(nieuw) - 1,2);



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
    