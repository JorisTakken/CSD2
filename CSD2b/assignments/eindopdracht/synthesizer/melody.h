#include <iostream>
#include "ui_input.h"
#include "math.h"


#pragma once

#define SAMPLERATE 44100

class Melody : public User_input{
public:
    Melody();
    ~Melody();

    void setScale();
    std::string getScale();
    void makeScale(std::string scale);
    void setMelodyType();
    // int generateMelody(std::string melodyType);




    void setNotelenght(int lenght);
    int getNotelenght();

    int fibonacci(int nextNote,int lenght);
    int random();

protected:
    int notelenght;
    int noteLengths[11] = {1,1,2,3,5,8,13,21,34,55,89};

    
    std::string scaleInput;
    std::string scale;

    int midiValues[8];
    int note = 0;
};