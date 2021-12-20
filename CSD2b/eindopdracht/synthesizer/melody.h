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




    void setNotelenght(int notelenght);
    int getNotelenght();
    
    int liniair(int nextNote);

protected:
    int notelenght;
    int noteLengths[3] = {44100,22050,11025};

    
    std::string scaleInput;
    std::string scale;

    int midiValues[8];
    int note = 0;
};