#include <iostream>
#pragma once
#include "instrument.h"

class String_instrument : public Instrument{ 
public:
    String_instrument(std::string instrument_naam,std::string pitch_range);
    ~String_instrument();

    void struming();
    void tokkelen();
    void number_of_String_instrument(int how_many_stings);

protected:
    int how_many_stings;
}; 