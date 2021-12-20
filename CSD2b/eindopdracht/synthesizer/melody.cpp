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
    std::string melodyOptions[3] = {"liniair", "random", "pauzed"};
    std::string melodyInput = make_userSelection(melodyOptions,3);
    std::cout << "your choise was : " << melodyInput << std::endl;
    // generateMelody(melodyInput);
}

void Melody::makeScale(std::string scale){
    int c7[8] = {48, 52, 55, 59, 60, 64, 67, 71};
    int dm7[8] = {50, 53, 57, 60, 62, 65, 69, 62};
    int g[8] = {47, 50, 55, 59, 62, 67, 71, 74};
    int randomScale[8];
    for (int i = 0; i < 8; i++){
        int randomVal = rand() % 40 + 50;  
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

// int Melody::generateMelody(std::string melodyType){
//     // int noteLengths[3] = {44100,22050,11025};
// //     for (int i = 0; i < 8; i++){
// //         std::cout << midiValues[i] << std::endl; 
// //     } 
// // }

int Melody::liniair(int nextNote){
    int midiNote_liniair[8] = {1,2,3,4,5,4,3,2};
    int midiOut = midiValues[midiNote_liniair[nextNote]];
    std::cout << midiOut << std::endl;
    return midiOut;
}







void Melody::setNotelenght(int notelenght){
    this->notelenght = noteLengths[notelenght];
}

int Melody::getNotelenght(){
    return notelenght;
}
