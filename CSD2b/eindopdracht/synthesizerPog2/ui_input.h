#include <iostream>
#include "wavetable.h"
#include "fm_synth.h"

#pragma once

class User_input{
    public:
        User_input();
        ~User_input();  

        // function for user selection of a list of strings
        // if there is nothing wrong witch input selection, returns input
        std::string make_userSelection(std::string selectionOptions[], int numOptions);

        // validate user input, 
        // if user choise is not in array :say "wrong input"
        bool validateSelection(std::string selection, std::string selectionOptions[],int numOptions);

        std::string retrieveUserInput(std::string selectionOptions[], int numOptions);
        
        // user input function for choosing number between chosen range
        int user_input_numbers(int min, int max);

        void userInitializeFMsynth();
        std::string getWaveFormCar(); 
        std::string getwaveFormMod();
        float getRatio();
        float getModDepth();

        void userInitializeWavetable(int numberOfOscillators);
        std::string getWaveforms(int next);
        int getMidiPitches(int next);
        int getNumberOfOscillators();

    protected:
        int numOptions;
        std::string selection;

        std::string waveFormCar;
        std::string waveFormMod;
        float ratio;
        float modDepth;

        std::string waveforms[MAX_OSCILLATORS];
        float midipitches[MAX_OSCILLATORS];


        int numberOfOscillators; 


};

