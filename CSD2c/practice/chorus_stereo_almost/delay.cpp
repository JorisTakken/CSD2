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



float Delay::process(float input){
    buffer[writePoint++] = input;
    writePoint = wrap(writePoint);

    ModDelay.setDelaytime((1 + mod.genNextSample()) * 1000 * 0.5);

    int readNext = readPoint + 1;
    float output = map(input,0,1,buffer[readPoint],buffer[readNext]);
    readPoint = wrap(readPoint);
    return output;

}

float Delay::setDelaytime(float newDelaytime){
    readPoint = writePoint - (int)newDelaytime;
    // readPoint = std::cout << readPoint << std::endl;
}       


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