#include <iostream>

#define SAMPLERATE 44100

class Saw{
public:
    Saw(std::string waveform,float frequency,float amplitude,int samplerate);
    ~Saw();


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
    std::string waveform;

    float sample;
    float phase;

};