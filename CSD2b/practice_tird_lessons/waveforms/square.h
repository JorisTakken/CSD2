#include <iostream>

#define SAMPLERATE 44100

class Square{
public:
    Square(std::string waveform,float frequency,float amplitude,int samplerate);
    ~Square();


    void setFrequency(float newfrequency);
    void setAmplitude(float newAmplitude);
    float getFrequency();
    float getAmplitude();

    float getSample();
    void tick();


protected:
    float newAmplitude;
    float newfrequency;
    float frequency;
    float amplitude;

    int samplerate;
    std::string waveform;

    float sample;
    float phase;
};