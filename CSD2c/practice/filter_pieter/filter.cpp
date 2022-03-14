#include "filter.h"
#include "bufferDebugger.h"


Filter::Filter(){
    buffer = new float[2];

}

Filter::~Filter(){  
    delete buffer;
    buffer = nullptr;
    delete writeBuf;
    writeBuf = nullptr;
}


float Filter::filter(int i){
    buffer[i] = 1;

}

float Filter::filter_out(){
    writeBuf = new float[1000];
    for(int i = 0; i < 1000; i++){
        float out = (buffer[i]) + (buffer[i-1]);
        writeBuf[i] = out;
    }
}  


void Filter::plot_waveshaper(){
    BufferDebugger::writeToFile(writeBuf, 1000, "output.csv");
}
