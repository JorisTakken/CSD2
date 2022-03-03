#include "modDelay.h"


ModDelay::ModDelay(int size,int delayMS, float modDelayRate) : Effect(44100), 
    size(size), modDelayRate(modDelayRate),samplesDelay(samplesDelay),
    writePoint(0), readPoint(readPoint){

    msToSamps(size);
    samplesDelay = msToSamps(delayMS);
    readPoint = size - samplesDelay;

    while (samplesDelay > size) {
        std::cout << "creash program" << std::endl;
        std::cout << "HELAAS  numSamplesDelay is groter dan size MAG NIET " << std::endl;
    }

    modDelayBuffer = new float[size];
    for(int i = 0; i < size; i++) {
        modDelayBuffer[i] = 0;
    }

    oscillator = new Sine(modDelayRate, samplerate);
}

ModDelay::~ModDelay(){
    delete [] modDelayBuffer;
    modDelayBuffer = nullptr;

    delete oscillator;
    oscillator = nullptr;

}   

void ModDelay::applyEffect(float& input, float& output)
{ 
  float modSignal = oscillator->getNextSample();  // float
  samplesDelay = modSignal + offset; // float
  float read_H_fp = (float) writeH - samplesDelay; // float
  readPoint = (int) read_H_fp; // int

  int readHNext = readHNext + 1; 
  // get decimal value
  float read_h_dec = read_H_fp - read_H; // float
  // wrap heads
  wrapH(readH); 
  wrapH(readHNext);
  
  output = inRange(read_h_dec, 0,1, modDelayBuffer[readH], modDelayBuffer[readHNext]);

  // write value to circular buffer
  modDelayBuffer[writeH++] = output * feedback + input;

  wrapH(m_writeH);
}


// float ModDelay::processEffect(float input){
//     float output;
//     modDelayBuffer[writePoint++] = input;
//     writePoint = wrap(writePoint);

//     output = modDelayBuffer[readPoint++];
//     readPoint = samplesDelay + inRange(oscillator->genNextSample(), -1, 1,samplesDelay, (samplesDelay + 2000));
//     // samplesDelay += (oscillator->genNextSample() * 1000);
//     // readPoint = wrap(readPoint);
//     return output;
// }


float ModDelay::wrap(int point){
    if (point >= size){
        point -= size; 
    }
    return point;
}

int ModDelay::inRange(float input, float x1, float x2 , int min, int max){
    // STARTING AT A X VALUE
    // std::cout << "input" << input << std::endl;

    int value = (min * (x2 - input) + max * (input - x1)) / (x2 - x1);  
    // std::cout << "modulated delay val:" << value << std::endl;
    return value;
}

int ModDelay::msToSamps(float miliseconds){
    return int((miliseconds * (samplerate / 1000.0)) + 0.5);
}



// ModDelay is a derived class from Delay 
// Effect <-- Delay <-- ModDelay


