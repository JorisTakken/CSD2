#include <iostream>
#include "instrument.h"

Instrument::Instrument(std::string instrument_naam){
    this->instrument_naam = instrument_naam;
}

Instrument::~Instrument(){    
}

void Instrument::play(){
    std::cout << instrument_naam << "  is playing now!\n";
}
    
void Instrument::pitch_range(){
}
