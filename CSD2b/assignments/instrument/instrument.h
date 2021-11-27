#include <iostream>

class Instrument{ 
public:
    Instrument(std::string instrument_naam);
    ~Instrument();

    void play();
    void pitch_range();

protected: 
    std::string instrument_naam;
};