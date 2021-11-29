#include <iostream>
#include "play_and_info.h"


All_instruments::All_instruments(std::string instrument_naam, std::string pitch_range) : Instrument(instrument_naam,pitch_range){
    this->instrument_naam = instrument_naam;
    this->pitch_range = pitch_range;
}

All_instruments::~All_instruments(){    
}


void All_instruments::play_string(std::string play_way){
    String_instrument string(instrument_naam,pitch_range);
    
    string.play_ins();
    if (play_way == "tokkel"){ 
        string.tokkelen();
    }
    else if (play_way == "strum"){ 
        string.struming();
    }
    else{ 
        std::cout << "This is no way of playing, try an other way,\n";
        std::cout << "choose 'strum' or 'tokkel' !,\n";
    }


}


void All_instruments::play_wind(){
    Wind_instrument wind(instrument_naam,pitch_range);
    wind.play_ins();
}

void All_instruments::info_string(int number_strings){
    String_instrument string(instrument_naam,pitch_range);
    string.pitchRange();
    string.number_of_String_instrument(number_strings);

    
}

void All_instruments::info_wind(std::string spectrum_place){
    Wind_instrument wind(instrument_naam,pitch_range);
    wind.place_in_spectrum(spectrum_place);
    wind.pitchRange();

    
}

