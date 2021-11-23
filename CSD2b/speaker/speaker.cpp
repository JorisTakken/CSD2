#include <iostream>

class Speaker 
{
public:
    Speaker();
    ~Speaker();
    void make_sound();
    float filter_freq; //filter cuttoff frequency
};

Speaker::Speaker() 
{
    filter_freq=205.4; //filter cuttoff frequency
}

Speaker::~Speaker()
{    
}








void Speaker::make_sound() 
{
    std::cout << "tadaaHijDoetiets?" << std:: endl;
    std::cout << "filterfreq   " << filter_freq << std:: endl;
}

int main()
{
    Speaker speaker_right;
    Speaker speaker_left;

    speaker_left.make_sound();
    speaker_left.filter_freq=402.4;
    speaker_left.make_sound();
}