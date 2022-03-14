#include "modDelay.h"
 
modDelay::modDelay(float chorusRate, float modDepth, int baseDelay, int samplerate) : Effect(44100),
    modDepth(modDepth), size(samplerate){
    int delayTimeSamps = msToSamps(baseDelay);
    this->delayTimeSamps = delayTimeSamps;

    oscillator = new Sine(chorusRate,samplerate);
    circBuffer = new CircBuffer(samplerate,0);
}

modDelay::~modDelay(){
    delete oscillator;
    oscillator = nullptr;

    delete circBuffer;
    circBuffer = nullptr;
}

void modDelay::applyEffect(float& input, float& output) {
    float modSig = input + (oscillator->genNextSample() * 0.5);   

    circBuffer->write(modSig);
    // circBuffer->setDistanceRW(modSig);
    output = circBuffer->read();
    circBuffer->tick();

    // float readPointFloat = (modSig * delayTimeSamps) * modDepth;
    // int readPointInt = (int)readPointFloat;
    // readNext = readNext + 1;

    
    // setDelaytime(writePoint - readPointInt);    

    // // std::cout << writePoint - readPointInt << std::endl;

    // output = map(readPointFloat - readPointInt,0,1,circBuffer.read(readPoint),circBuffer.read(readNext));
    // readNext = wrap(readNext);
    // readPoint = wrap(readPoint); 
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