#include "filter.h"



Filter::Filter(){
    buffer = new float[1000];
    sine = new Sine(400,44100);

}

Filter::~Filter(){  
    delete buffer;
    buffer = nullptr;
    delete writeBuf;
    writeBuf = nullptr;
    delete sine;
    sine = nullptr;
}


float Filter::filter(int i){
    // std::cout << sine->genNextSample() << std::endl;
    buffer[i] = 1;

}

float Filter::filter_out(){
    writeBuf = new float[1000];
    for(int i = 0; i < 1000; i++){
        float out = (0.5*(buffer[i])) + (0.5*(buffer[i-1]));
        writeBuf[i] = out;
    }
}  




void Filter::plot_waveshaper(){
    BufferDebugger::writeToFile(writeBuf, 1000, "output.csv");
}
