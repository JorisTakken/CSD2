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



// wavetable had no function of using a melody buy has as many oscillators as you want (up to 20)

// -----------------------------------------------------------------------
// function to choose the synth you want to hear
// -----------------------------------------------------------------------
std::string chooseSynth(){
    User_input synthSel;
    std::cout << "==============================================" << std::endl;
    std::cout << "choose your synth : FM (fm) wavetable (w)" << std::endl;
    std::string synthChoises[2] = {"fm","w"};
    std::string synthChoise = synthSel.makeUserSelection(synthChoises,2);
    std::cout << "synthChoise " << synthChoise << std::endl;
    std::cout << "==============================================" << std::endl;
    
    return synthChoise;
}

// -----------------------------------------------------------------------
// function choose how many oscillators in wavetable you want
// -----------------------------------------------------------------------
int chooseNumOscillators(){
    User_input oscillatorsNumber;
    std::cout << "choose how many oscillators you want (from 1 - 20)" << std::endl;
    // int numberOfOscillators;
    int numberOfOscillators = oscillatorsNumber.userInputNumbers(1,20);
    std::cout << "number of oscillators " << numberOfOscillators << std::endl;
    std::cout << "==============================================" << std::endl;
    
    return numberOfOscillators;
}

int main(int argc,char **argv){
    Synth* synth = nullptr;
    User_input init;
    Melody melo;

    // choose synth
    std::string synthChoise = chooseSynth();

    if (synthChoise == "fm"){

        // if FM synth is chosen make FM synth and user input initialises synth
        synth = new FM_synth;
            init.userInitializeFMsynth();
        ((FM_synth*)synth)->initialize(init.getWaveFormCar(),init.getwaveFormMod(),60,init.getRatio(),init.getModDepth());
        
        // only in FM synth you can choose a melody
            melo.setScale(); 
            melo.setMelodyType(); 
    }
    else if (synthChoise == "w"){

        // if wavetable synth is chosen make wavetable synth and user input initialises synth
        synth = new Wavetable;
        std::string waveform[20] = {};
        int midipitch[20] = {};  
        int numberOfOscillators = chooseNumOscillators();
        init.userInitializeWavetable(numberOfOscillators);  
              
        for (int i = 0; i < numberOfOscillators; i++){
            waveform[i] = init.getWaveforms(i);
            midipitch[i] = init.getMidiPitches(i);
        }
        ((Wavetable*)synth)->initialize(waveform,midipitch,numberOfOscillators);
    }


// -----------------------------------------------------------------------
// every time you make a sound you can plot it with the python plotter 
// made by : Ciska Vriezenga
// -----------------------------------------------------------------------
WriteToFile fileWriter("_waveForm.csv", true);
if(synth != nullptr) {
  // hier je forloop 
    for(int i = 0; i < SAMPLERATE; i++) {
        fileWriter.write(std::to_string(synth->nextSample()) + "\n");
    }
}
    
    float amplitude = 0.2;
    int framecount = 0;
    int interval = 44100;
    int nieuw = 1;
    int lenght = 0;
    std::string meloType = melo.getMelodyType();

    JackModule jack;
    jack.init(argv[0]);
    jack.onProcess = [&synth, &melo, &amplitude, &framecount, &interval, &lenght, &nieuw, &synthChoise, &meloType]
    (jack_default_audio_sample_t *inBuf, jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
        for(unsigned int i = 0; i < nframes; i++) {
                // send samples calulated in synth to jack audio
                outBuf[i] = synth->nextSample() * amplitude;
                if (synthChoise == "fm"){
                    framecount++;

                    // every intervall is a notelenght in array of fibonacci class
                    if (framecount > interval){
                        lenght++;
                        if (lenght == 10){
                            lenght = 0;
                        }

                        // make notlenght melody 
                        interval = (melo.getNotelenght());
                        

                        // new pitch every interval
                        nieuw++;
                        if (nieuw == 8){  
                            nieuw = 0;
                        }

                        // if melody is different, an different melody is comming
                        if (meloType == "f"){
                            std::cout << melo.fibonacci(nieuw,lenght) << std::endl;
                            synth->setMidiPitch(melo.fibonacci(nieuw,lenght) - 12,0);   
                        }else if (meloType == "r"){
                            std::cout << melo.random() << std::endl;
                            synth->setMidiPitch(melo.random() - 12,0);  

                        }
                        
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
    return 0;
} 