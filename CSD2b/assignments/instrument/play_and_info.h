#include <iostream>
#include "instrument.h"
#include "strings.h"
#include "wind_instrument.h"



class Play_info : public Instrument{ 
public:
    Play_info(std::string instrument_naam, std::string pitch_range);
    ~Play_info();

    String_instrument inst_string("inst","hz");
    Wind_instrument inst_wind("inst","hz");
    Instrument inst("inst","hz");
    



    void play();
    void info();


protected: 

};