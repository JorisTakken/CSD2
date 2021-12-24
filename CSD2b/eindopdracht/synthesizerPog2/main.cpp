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

// #define WRITE_TO_FILE 1

#define NUMBER_OSCILLATORS 5

std::string chooseSynth(){
    User_input synthSel;
    std::cout << "==============================================" << std::endl;
    std::cout << "choose your synth : FM (fm) wavetable (w)" << std::endl;
    std::string synthChoises[2] = {"fm","w"};
    std::string synthChoise = synthSel.make_userSelection(synthChoises,2);
    std::cout << "synthChoise " << synthChoise << std::endl;
    std::cout << "==============================================" << std::endl;
    
    return synthChoise;
}

int chooseNumOscillators(){
    User_input oscillatorsNumber;
    std::cout << "==============================================" << std::endl;
    std::cout << "choose how many oscillators you want (from 1 - 20)" << std::endl;
    // int numberOfOscillators;
    int numberOfOscillators = oscillatorsNumber.user_input_numbers(1,20);
    std::cout << "number of oscillators " << numberOfOscillators << std::endl;
    std::cout << "==============================================" << std::endl;
    
    return numberOfOscillators;
}


int main(int argc,char **argv){
    Synth* synth = nullptr;
    User_input init;
    Melody melo;

    std::string synthChoise = chooseSynth();

    if (synthChoise == "fm"){
        synth = new FM_synth;
            init.userInitializeFMsynth();
        ((FM_synth*)synth)->initialize(init.getWaveFormCar(),init.getwaveFormMod(),60,init.getRatio(),init.getModDepth());
            melo.setScale(); 
            melo.setMelodyType(); 
    }
    else if (synthChoise == "w"){
        synth = new Wavetable;
            int numberOfOscillators = chooseNumOscillators();
            init.userInitializeWavetable(numberOfOscillators);  
            std::string waveform[20] = {};
            int midipitch[20] = {};    
            for (int i = 0; i < numberOfOscillators; i++){
                waveform[i] = init.getWaveforms(i);
                midipitch[i] = init.getMidiPitches(i);
            }
        ((Wavetable*)synth)->initialize(waveform,midipitch,numberOfOscillators);
    }

    
// #if WRITE_TO_FILE
WriteToFile fileWriter("_waveForm.csv", true);

if(synth != nullptr) {
  // hier je forloop 
    for(int i = 0; i < SAMPLERATE; i++) {
        fileWriter.write(std::to_string(synth->nextSample()) + "\n");
    }
}
    
// #else
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
                }else if (synthChoise == "w"){
                
                }
            }
        }
        return 0;
    };
    // delete synth;
    // synth = nullptr;
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
// #endif
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
    