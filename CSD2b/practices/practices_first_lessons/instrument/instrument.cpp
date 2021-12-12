#include <iostream>

class Instrument{
public: 
    Instrument();
    ~Instrument();

    void sound(std::string sound_kind);
    void freq(int frequencies);
    void sinus_function(int sinus_frequencies);
};

Instrument::Instrument(){
}

Instrument::~Instrument(){
}

void Instrument::sound(std::string sound_kind){
    std::cout << "kind of sound " << sound_kind << std:: endl;
}

void Instrument::freq(int frequencies){
    std::cout << "frequencie : " << frequencies << std:: endl;
}

void Instrument::sinus_function(int sinus_frequencies){
    std::cout << "frequencie sinus : " << sinus_frequencies << std:: endl;
}





int main(){ 
    int j;
    int freq_sinus [10] = { 10, 20, 30,40,50,60,70,80,90,100};
    
    for (j = 0; j < 10; j++){
    Instrument sinus[j];
    sinus[j].sinus_function(freq_sinus[j]);
    };

    Instrument synth;
    Instrument instrument_happy;
    Instrument instrument_sad;
    Instrument instrument_neutral;


    instrument_happy.sound("happy");
    instrument_sad.sound("sad");
    instrument_neutral.sound("neutral");

    int i;
    int freq [10] = { 250, 300, 441, 643, 690, 700,820,200, 1000 , 2102};
    
    for (i = 0; i < 10; i++){
    synth.freq(freq[i]);
    };


    
    
    


    // for (i = 0; i < 10; i++){
    //     instrument[i].sound(i);





}