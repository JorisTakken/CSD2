#include <iostream>
#include "oscillator.h"

#define SAMPLERATE 44100

class Square : public Oscillator{
public:
    Square(float frequency,float amplitude,int samplerate);
    ~Square();


    void setFrequency(float frequency);
    void setAmplitude(float amplitude);
    float getFrequency();
    float getAmplitude();

    float getSample();
    void tick();


protected:
    float frequency;
    float amplitude;
    int samplerate;

    float sample;
    float phase;

};