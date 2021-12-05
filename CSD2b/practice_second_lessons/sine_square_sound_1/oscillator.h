#include <iostream>

class Oscillator{
    public:
        Oscillator(std::string waveform, float frequencie, float amplitude, int samplerate);
        ~Oscillator();
        void changeWaveform(std::string waveform);
        void playWaveform(std::string waveform, float frequencie, float amplitude, int samplerate);

    protected:
    std::string waveform;
    float frequencie;
    float amplitude;
    int samplerate;
};