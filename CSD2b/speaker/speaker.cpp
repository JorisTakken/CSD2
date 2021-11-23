#include <iostream>
#include "speaker.h"

Speaker::Speaker() 
{
    std::cout << "Constructor" << std:: endl;

    filter_freq=205.4; //filter cuttoff frequency
}

Speaker::~Speaker()
{
    std::cout << "Decostructor" << std:: endl;
    
}

void Speaker::make_sound() 
{
    std::cout << "tadaaHijDoetiets?" << std:: endl;
    std::cout << "filterfreq   " << filter_freq << std:: endl;
}


