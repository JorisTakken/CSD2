#include <iostream>
#include "instrument.h"

class String_instrument : public Instrument{ 
public:
    String_instrument(std::string instrument_naam);
    ~String_instrument();

    void struming();
    void tokkelen();
    void number_of_String_instrument(int how_many_stings);

protected:
    int how_many_stings;
}; 