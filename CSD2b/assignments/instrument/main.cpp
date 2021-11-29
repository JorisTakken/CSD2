#include <iostream>

#include "strings.h"
#include "play_and_info.h"
#include "wind_instrument.h"


int main(){  
    All_instruments gitaar("<gitaar>","82.41Hz , 329.63Hz");
    All_instruments bass("<bass>","60Hz , 250Hz");
    All_instruments trumpet("<trumpet>","164.8Hz , 932.3Hz");
    All_instruments saxephone("<saxephone>","138Hz , 830Hz");

    std::string p_or_i;
    std::cout << "choose to play instruments or get info of instruments,\n";
    std::cout << "(play) (info),\n";
    std::cin >> p_or_i;
    std::cout << "__-_,\n";

    if (p_or_i == "play"){
        std::string s_or_t;
        std::cout << "would you like the string instrument to be strumming or tokkelen?,\n";
        std::cout << "(strum) (tokkel),\n";
        std::cin >> s_or_t;
        std::cout << "__-_-_,\n";

        gitaar.play_string(s_or_t);
        bass.play_string(s_or_t);
        saxephone.play_wind();
        trumpet.play_wind(); 
    }

     if (p_or_i == "info"){
        std::string user_question_spectrum_sax;
        std::cout << "In what part of the EQ spectrum is the saxephone?,\n";
        std::cout << "(low) (mid) (high),\n";
        std::cin >> user_question_spectrum_sax;
        std::cout << "__-_-_,\n";

        std::string user_question_spectrum_trump;
        std::cout << "In what part of the EQ spectrum is the trumpet?,\n";
        std::cout << "(low) (mid) (high),\n";
        std::cin >> user_question_spectrum_trump;
        std::cout << "__-_-_,\n";

        int strings_git;
        std::cout << "howmany string does a guitar have,\n";
        std::cin >> strings_git;
        std::cout << "__-_-_,\n";

        int strings_bass;
        std::cout << "howmany string does a bass have,\n";
        std::cin >> strings_bass;
        std::cout << "__-_-_,\n";


        saxephone.info_wind(user_question_spectrum_sax);
        trumpet.info_wind(user_question_spectrum_trump); 
        bass.info_string(strings_bass);
        gitaar.info_string(strings_git);
     }
    

    
  
}


