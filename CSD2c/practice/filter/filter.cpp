#include "filter.h"

Filter::Filter() : Effect(samplerate){
    buffer = new float[1];
}

Filter::~Filter(){  
    delete buffer;
    buffer = nullptr;
}


void Filter::processEffect(float& input,float& output){
    buffer[writeIndex++] = input;
    // std::cout << readIndex << std::endl;

    writeIndex = wrap(writeIndex);

    readIndex = readIndex + 1;
    output = buffer[readIndex] - buffer[readIndex-1];
    readIndex = wrap(readIndex);

    // output = input;

    

} 

void Filter::plot_waveshaper(){
    // BufferDebugger::writeToFile(writeBuf, 1000, "output.csv");
}

int Filter::wrap(int head){
    if(head>=2) head -=2;
    return head;
}



// // Create a Chebyshev type I Band Stop filter of order 3
Dsp::SimpleFilter <Dsp::ChebyshevI::BandStop <3>, 2> f;
f.setup (3,    // order 
44100,// sample rate
4000, // center frequency
880,  // band width
1);   // ripple dB
// f.process (numSamples, arrayOfChannels);