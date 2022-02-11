#include "melody.h"


#define SAMPLERATE 44100

Melody::Melody() : User_input(){
}

Melody::~Melody(){
}
// -----------------------------------------
// set scale of melody with userinput 
// -----------------------------------------
void Melody::setScale(){
    std::string scaleOptions[4] = {"C7", "Dm7", "G", "random"};
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::string scaleInput = makeUserSelection(scaleOptions,4);
    std::cout << "your choise was : " << scaleInput << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    makeScale(scaleInput);
}

std::string Melody::getScale(){
    return scaleInput;
}

// -----------------------------------------
// set melody type with userinput
// -----------------------------------------
void Melody::setMelodyType(){
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "What kind of melody would you like?" << std::endl;
    std::cout << "Fibonacci (f),random (r)" << std::endl;
    std::string melodyOptions[2] = {"f", "r"};
    std::string melodyInput = makeUserSelection(melodyOptions,2);
    this->melodyInput = melodyInput;
    std::cout << "your choise was : " << melodyInput << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
}

std::string Melody::getMelodyType(){
    return melodyInput;
}


// ----------------------------------------------------------------------------------
// make scale and put it in the midiValues so we can use it for generation og melodys
// ----------------------------------------------------------------------------------
void Melody::makeScale(std::string scale){
    // scales are midinots in scales
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

// ----------------------------------------------------------------------------------
// fibonnacci method:
// i made a melody generator with the famous fibbonnacci list
// the notelengts are based on the fibbonnacci list it goes from really fast to slow exponential.
// so 0 + 1 = 1; 1 + 1 = 2; 1 + 2 = 3; 3 + 2 = 5; 5 + 3 = 8; ext.
// see "noteLengths[]" in melody.h
// ----------------------------------------------------------------------------------
int Melody::fibonacci(int nextNote,int lenght){
    int fibonacciNotes[8] = {1,2,4,5,2,4,1,5};
    int midiOut = midiValues[fibonacciNotes[nextNote]];
    setNotelenght(lenght);
    return midiOut;
}

// ----------------------------------------------------------------------------------
// random method:
// next note is a random note of the scale
// it uses random notelenghts of fibonacci list
// ----------------------------------------------------------------------------------
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

