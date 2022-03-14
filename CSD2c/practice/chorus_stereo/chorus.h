#pragma once
#include <iostream>
#include "circBuffer.h"
#include "sine.h"
#include "effect.h"

class Chorus : public Effect{
  public:
    Chorus(float modFreq, float modDepth, int delayMS,float feedback, float samplerate);
    ~Chorus();

    void processEffect(float &input, float &output) override;
    void setDelayMS(float delayMilsec);

  protected:
    float map(float input, int x1, int x2 , float min, float max);

    int size;
    int delaySamps;
    float modulation;
    float feedback;
    int delayMS;
    float modDepth;
    CircBuffer* circBuffer;
    Oscillator* oscillator;
  private:

};