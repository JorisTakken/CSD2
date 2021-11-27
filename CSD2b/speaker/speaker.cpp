#include <iostream>
#include "speaker.h"

Speaker::Speaker() 
{
    filter_freq=205.4; //filter cuttoff frequency
}

Speaker::~Speaker()
{
    
}

void Speaker::make_sound(float freq) 
{
    std::cout << "filterfreq   " << filter_freq << std:: endl;

    if (freq >= filter_freq){
        tweeter.tweet();
    }
    else {
        woofer_big.woof();
        woofer_normal.woof();

    }


}


