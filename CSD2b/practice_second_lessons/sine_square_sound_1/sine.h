#include <iostream>
#include "oscillator.h"
#define SAMPLERATE 44100

class Sine : public Oscillator{
public:
    Sine(float frequency, float amplitude, int samplerate);
    ~Sine();


    void setFrequency(float frequency);
    void setAmplitude(float amplitude);
    float getFrequency();
    float getAmplitude();

    float getSample();
    void tick();

    void list_of_values(std::string values_sine);

protected:
    float frequency;
    float amplitude;
    int samplerate;

    float sample;
    float phase;

    std::string value_sine;
    std::string values_sine[100];
};