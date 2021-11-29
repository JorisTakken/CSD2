#include <iostream>
#include "instrument.h"

Instrument::Instrument(std::string instrument_naam, std::string pitch_range){
    this->instrument_naam = instrument_naam;
    this->pitch_range = pitch_range;

}

Instrument::~Instrument(){    
}

void Instrument::play_ins(){
    std::cout << instrument_naam << "  is playing now!\n";
}
    
void Instrument::pitchRange(){
    std::cout << "the pitch range of the instrument " << instrument_naam << " is " << pitch_range << " \n";
    
}
