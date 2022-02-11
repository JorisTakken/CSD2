#include <iostream>
#include "ui_input.h"
#include "math.h"

#pragma once

#define SAMPLERATE 44100

// -----------------------------------------------------
// melody is a subclass of UIinputclass
// melody has its own UI input functions
// -----------------------------------------------------
class Melody : public User_input{
public:
    Melody();
    ~Melody();

    // function to set scale of your melody
    void setScale();
    std::string getScale();

    // -----------------------------------------------------
    // make scale using midinotes in scale 
    // -----------------------------------------------------
    void makeScale(std::string scale);
    // set type of melody (random or fibonacci)
    void setMelodyType();
    std::string getMelodyType();

    void setNotelenght(int lenght);
    int getNotelenght();

    // generate melody based on fibonacci list
    int fibonacci(int nextNote,int lenght);
    // generate melody based on random notes in scale and random notelengts of fibonacci
    int random();

protected:
    int notelenght;
    
    // -----------------------------------------------------
    // fibonacci list
    // -----------------------------------------------------
    int noteLengths[11] = {1,1,2,3,5,8,13,21,34,55,89};
    
    std::string scaleInput;
    std::string scale;

    int midiValues[8];
    int note = 0;
};