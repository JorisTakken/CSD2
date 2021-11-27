#include <iostream>

class Oscillator{
public: 
    Oscillator(float freq, float amp);
    ~Oscillator();

    void setFreq(float freq);
    float getFreq();


protected:
    float freq;
    float amp;
};
