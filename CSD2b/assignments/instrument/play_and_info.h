#include <iostream>
#include "instrument.h"
#include "strings.h"
#include "wind_instrument.h"



class All_instruments : public Instrument{ 
public:
    All_instruments(std::string instrument_naam, std::string pitch_range);
    ~All_instruments();
    
    void play_string(std::string play_way);
    void play_wind();

    void info_wind(std::string spectrum_place);
    void info_string(int number_strings);



protected: 
    std::string instrument_naam;
    std::string pitch_range;
};