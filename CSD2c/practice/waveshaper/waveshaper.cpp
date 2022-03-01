#include "waveshaper.h"
#include "math.h"
#include "bufferDebugger.h"


Waveshaper::Waveshaper(int buffersize) : buffersize(buffersize){
    wavetableBuffer = new float[buffersize];
}

Waveshaper::~Waveshaper(){
    delete wavetableBuffer;
}

void Waveshaper::genWaveshape(float sharpness){
    // THANKS TO CISKA MARC AND Pirkle 2013, "Designing Audio Effect Plug-ins in C++" p. 497
    float normalizeFactor = 1.0f / atan(sharpness);
    for(int i = 0; i < buffersize; i++) {
        float mappedVal = map((float)i, 0, buffersize, -1.0f, 1.0f);
        wavetableBuffer[i] = normalizeFactor * atan(sharpness * mappedVal);
  }
}

float Waveshaper::interpolation(float input){
    float index = (input + 1) * (buffersize/2);
    int i = (int) index;
    float indexDecimal = index - float(i);
    return map(indexDecimal,0,1, wavetableBuffer[i], wavetableBuffer[i + 1]);
}

float Waveshaper::map(float input, int x1, int x2 , float min, float max){
    // STARTING AT A X VALUE
    float value = (min * (x2 - input) + max * (input - x1)) / (x2 - x1);    
    return value;
}

void Waveshaper::plot_waveshaper(){
    BufferDebugger::writeToFile(wavetableBuffer, buffersize, "output.csv");
}