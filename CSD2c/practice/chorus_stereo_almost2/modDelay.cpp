#include "modDelay.h"
 
modDelay::modDelay(float chorusRate, float modDepth, int baseDelay, int samplerate) : Delay(44100, 0, 0),
    modDepth(modDepth), size(samplerate){
    int delayTimeSamps = msToSamps(baseDelay);
    this->delayTimeSamps = delayTimeSamps;

    oscillator = new Sine(chorusRate,samplerate);
    delay = new Delay(samplerate, 0, 0);
}

modDelay::~modDelay(){
}

void modDelay::applyEffect(float& input, float& output) {
    writeBuffer(input);

    float modSig = (1 + oscillator->genNextSample()) * 0.5;   
    float readPointFloat = (modSig * * delayTimeSamps) * modDepth;
    int readPointInt = (int)readPointFloat;
    readNext = readNext + 1;

    
    setDelaytime(writePoint - readPointInt);    

    // std::cout << writePoint - readPointInt << std::endl;

    output = map(readPointFloat - readPointInt,0,1,buffer[readPoint],buffer[readNext]);
    readNext = wrap(readNext);
    readPoint = wrap(readPoint); 
}  

int modDelay::msToSamps(float miliseconds){
    return int((miliseconds * (44100 / 1000.0)) + 0.5);
}

float modDelay::wrap(int point){
    if (point >= size){
        point -= size; 
    }
    return point;
}









// void ModDelay::applyEffect(float& input, float& output)
// { 
//   modSignal = osc->getNextSample() * modDepth;  // float
//   delayTimeSamples = modSignal + offset; // float
//   read_H_fp = (float) writeH - delayTimeSamples; // float
//   readH = (int) read_H_fp; // int
//   readHNext = readHNext + 1; 
//   // get decimal value
//   read_h_dec = read_H_fp - read_H; // float
//   // wrap heads
//   wrapH(readH); 
//   wrapH(readHNext);
  
//   output = linMap(read_h_dec, buffer[readH], buffer[readHNext]);

//   // write value to circular buffer
//   buffer[writeH++] = output * feedback + input;

//   wrapH(m_writeH);
// }