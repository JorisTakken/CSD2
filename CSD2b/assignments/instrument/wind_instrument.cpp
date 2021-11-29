#include <iostream>
#include "wind_instrument.h"

Wind_instrument::Wind_instrument(std::string instrument_naam,std::string pitch_range) : Instrument(instrument_naam,pitch_range){
}

Wind_instrument::~Wind_instrument(){
}

void Wind_instrument::place_in_spectrum(std::string spectrum){
    this->spectrum = spectrum;
    std::cout << instrument_naam << " is in the " << spectrum << " part of the EQ spectrum  \n";
}

