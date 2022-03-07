#include "delay.h"


Delay::Delay(int size, int numSamplesDelay, float feedback) : 
    size(size), numSamplesDelay(numSamplesDelay),
    writePoint(0), readPoint(0), feedback(feedback){ 
    
    // numSamplesDelay = msToSamps(numSamplesDelay);

    while (numSamplesDelay > size) {
        std::cout << "MAG NIET, kies andere sampledelay!" << std::endl;
        std::cout << "kies maar : " << std::endl;
        int input;
        std::cin >> input;
        numSamplesDelay = input;
    }
    buffer = new float[size];
    for(int i = 0; i < size; i++) {
        buffer[i] = 0;
    }
}

Delay::~Delay(){
    delete [] buffer;
    buffer = nullptr;
}

// void Delay::processEffect(float &input, float &output){
//     buffer[writePoint++] = input + (output * feedback);
//     writePoint = wrap(writePoint);
    
//     output = buffer[readPoint++];
//     readPoint = wrap(readPoint);
// }



float Delay::setDelayTimeNumSamples(float newTime,float input){
    
    float read_floatingP = (float) writePoint - newTime;
    readPoint = (int) read_floatingP;
    float read_h_dec = read_floatingP - readPoint; 
    std::cout << readPoint << "  " << writePoint << std::endl;

    readNext = readNext + 1; 

    readPoint = wrap(readPoint);
    readNext = wrap(readNext);
    
    float output = map(read_h_dec,0 ,1 , buffer[readPoint], buffer[readNext]);

    buffer[writePoint++] = input;
    writePoint = wrap(writePoint);
    return output;

}

// float Delay::genNextSample(float inputsamp){
    
//     float outputSamp = buffer[readPoint++];
//     readPoint = wrap(readPoint);
    
// }


float Delay::map(float input, int x1, int x2 , float min, float max){
    // STARTING AT A X VALUE
    float value = (min * (x2 - input) + max * (input - x1)) / (x2 - x1);    
    return value;
}

float Delay::getDistance(){   
    if(writePoint < readPoint) {
        int flip = writePoint;
        flip += size;
        return flip - readPoint;
    }
    return writePoint - readPoint;
}

float Delay::wrap(int point){
    if (point >= size){
        point -= size; 
    }
    return point;
}




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