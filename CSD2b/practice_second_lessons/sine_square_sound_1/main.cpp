#include <iostream>
#include <thread>
#include "jack_module.h"
#include "sine.h"
#include "square.h"
#include "oscillator.h"
#include "writeToFile.h"

// #define  1

int main(){  
    Sine sine(10,0.5);
    Square square(10,0.5);

    // wat je dus wilt is een class waarmee je waveform, freq, ampli en samplerate zegt
    // Oscillator sine("sine",100,0.5,samplerate)

}

