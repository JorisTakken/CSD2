#include <iostream>
#include "oscillator.h"
#define SAMPLERATE 44100

class Sine : public Oscillator{
public:
    Sine(std::string waveform,float frequency, float amplitude, int samplerate);
    ~Sine();

    void setFrequency(float newfrequency);
    void setAmplitude(float newAmplitude);
    float getFrequency();
    float getAmplitude();

    float getSample();
    void tick();

    void list_of_values(std::string values_sine);

protected:
    float frequency;
    float newfrequency;
    float amplitude;
    float newAmplitude;

    int samplerate;

    float sample;
    float phase;
    std::string waveform;
    std::string values_sine[100];
};