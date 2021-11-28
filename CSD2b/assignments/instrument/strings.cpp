#include <iostream>
#include "strings.h"

String_instrument::String_instrument(std::string instrument_naam,std::string pitch_range) : Instrument(instrument_naam,pitch_range){
}

String_instrument::~String_instrument(){
}

void String_instrument::struming(){
    std::cout << instrument_naam << "  is strumming \n";
}

void String_instrument::tokkelen(){
    std::cout << instrument_naam << "  is aan het tokkelen\n";

}

void String_instrument::number_of_String_instrument(int how_many_stings){
    this->how_many_stings = how_many_stings;
    std::cout << instrument_naam << " sting instrument has: " << how_many_stings << " strings\n";
} 