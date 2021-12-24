#include <iostream>

#define SAMPLERATE 44100

class Square{
public:
    Square(float frequency,float amplitude);
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

    float sample;
    float phase;

};