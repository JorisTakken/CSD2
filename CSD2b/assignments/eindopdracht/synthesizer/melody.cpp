#include "melody.h"


#define SAMPLERATE 44100

Melody::Melody() : User_input(){
}

Melody::~Melody(){
}

void Melody::setScale(){
    std::string scaleOptions[4] = {"C7", "Dm7", "G", "random"};
    std::string scaleInput = make_userSelection(scaleOptions,4);
    std::cout << "your choise was : " << scaleInput << std::endl;
    makeScale(scaleInput);
}

std::string Melody::getScale(){
    return scaleInput;
}

void Melody::setMelodyType(){
    std::cout << "What kind of melody would you like?" << std::endl;
    std::cout << "Fibonacci (f),random (r)" << std::endl;
    std::string melodyOptions[2] = {"f", "r"};
    std::string melodyInput = make_userSelection(melodyOptions,2);
    std::cout << "your choise was : " << melodyInput << std::endl;
}

void Melody::makeScale(std::string scale){
    int c7[8] = {48, 52, 55, 59, 60, 64, 67, 71};
    int dm7[8] = {50, 53, 57, 60, 62, 65, 69, 62};
    int g[8] = {47, 50, 55, 59, 62, 67, 71, 74};
    int randomScale[8];
    for (int i = 0; i < 8; i++){
        int randomVal = rand() % 40 + 30;  
        randomScale[i] = randomVal;
    } 

    if (scale == "C7"){
        for (int i = 0; i < 8; i++){
            this->midiValues[i] = c7[i];
        }  
    }
    else if (scale == "Dm7"){
        for (int i = 0; i < 8; i++){
            this->midiValues[i] = dm7[i];
        }  
    }
    else if (scale == "G"){
        for (int i = 0; i < 8; i++){
            this->midiValues[i] = g[i];
        }  
    }
    else if (scale == "random"){
        for (int i = 0; i < 8; i++){
            this->midiValues[i] = randomScale[i];
        }  
    }
}



int Melody::fibonacci(int nextNote,int lenght){
    int midiNote_liniair[8] = {1,2,3,5,3,4,2,1};
    int midiOut = midiValues[midiNote_liniair[nextNote]];
    setNotelenght(lenght);
    return midiOut;
}

int Melody::random(){
    int nextnote = rand() % 8; 
    int midiOut = midiValues[nextnote];
    setNotelenght(nextnote);
    return midiOut;
}

void Melody::setNotelenght(int lenght){
    this->notelenght = noteLengths[lenght] * 1225;
}

int Melody::getNotelenght(){
    return notelenght;
}

