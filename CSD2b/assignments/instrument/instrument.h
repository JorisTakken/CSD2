#include <iostream>
#pragma once

class Instrument{ 
public:
    Instrument(std::string instrument_naam, std::string pitch_range);
    ~Instrument();

    void play();
    void pitchRange();

protected: 
    std::string instrument_naam;
    std::string pitch_range;
};