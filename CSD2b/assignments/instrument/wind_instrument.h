#include <iostream>
#include "instrument.h"

class Wind_instrument : public Instrument{ 
public:
    Wind_instrument(std::string instrument_naam,std::string pitch_range);
    ~Wind_instrument();

    void place_in_spectrum(std::string spectrum);

protected:
    std::string spectrum;
}; 