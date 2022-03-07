#include "modDelay.h"

// #define samplerate 44100

// chorusrate = frequencie
// moddepth = from 0 - 1
modDelay::modDelay(float chorusRate, float modDepth, float baseDelay) : Delay(44100,baseDelay,feedback),
  modDepth(modDepth), baseDelay(baseDelay), writePoint(0), size(44100), samplerate(44100) {

    buffer = new float[size];
    oscillator = new Sine(chorusRate, samplerate);
    delay = new Delay(44100, 50, 0);

}
modDelay::~modDelay(){
    delete [] buffer;
    buffer = nullptr;

    delete oscillator;
    oscillator = nullptr;
}

// ModDelay is a derived class from Delay 
// Effect <-- Delay <-- ModDelay

float modDelay::applyEffect(float input) {
  // modSignal is a float 
  float modSignal = oscillator->genNextSample() * modDepth; 
  /*
   * offset is a float, 
   * setDelayTimeNumSamples is an overloaded method: 
   * • one accepts an int
   * • one accepts a float --> use interpolated read from buffer 
   */
  delay->setDelaytime((int)(modSignal + 0.2));
  float sample = delay->genNextSample(input);
  return sample;
}

// float modDelay::map(float input, int x1, int x2 , float min, float max){
//     // STARTING AT A X VALUE
//     float value = (min * (x2 - input) + max * (input - x1)) / (x2 - x1);    
//     return value;
// }

float modDelay::wrap(int point){
    if (point >= size){
        point -= size; 
    }
    return point;
}

int modDelay::msToSamps(float miliseconds){
    return miliseconds / 1000.0f * samplerate; 
}


// float modDelay::mapLin(float normValue, float low, float high)
// {
//   if(normValue < 0 || normValue > 1) {
//     throw "WavetableGenerator::mapLin - value is not a normalized value";
//   }
//   // apply linear mapping
//   // low + (high - low) * valueBehindComma
//   float delta = high - low;
//   return (normValue * delta) + low;
// }






// void modDelay::processEffect(float& input, float& output){ 
      
//     // std::cout << oscillator << std::endl;
//     float modulationChorus = modDepth * oscillator->genNextSample(); //float
//     float modSignal = modulationChorus + baseDelay; //float 
//     modSignal = msToSamps(modSignal); //float to int
//     readPoint = (int)modSignal; //int
//     float interpol =  modSignal - readPoint;
//     int readNext = 0;
//     readNext += 1;


//     buffer[writePoint++] = input;
//     writePoint = wrap(writePoint); 

//     output = map(interpol, 0, 1,  buffer[readPoint], buffer[readNext]);
    
//     // output = buffer[readPoint++];
//     readPoint = wrap(readPoint);
//     readNext = wrap(readNext);
// }
