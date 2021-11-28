#include <iostream>
#include "strings.h"
#include "wind_instrument.h"


// stinginstruments
// struming();
// tokkelen();
// number_of_String_instrument(int number_of_String_instrument);



int main(){
    String_instrument gitaar("<gitaar>","82.41Hz , 329.63Hz");
    String_instrument bass("<bass>","60Hz , 250Hz");
    Wind_instrument trumpet("<trumpet>","164.8Hz , 932.3Hz");
    Wind_instrument saxephone("<saxephone>","138Hz , 830Hz");

    std::string info_or_play; 
    std::cout << "would you like to play the instrument or know information about them?" << "\n";
    std::cout << "(info) (play)" << "\n";


    std::cin >> info_or_play;
    std::cout << info_or_play << "\n";


    if (info_or_play == "info"){ 
        saxephone.place_in_spectrum("mid");
        saxephone.pitchRange();
        trumpet.place_in_spectrum("high");
        trumpet.pitchRange();
        gitaar.number_of_String_instrument(6);
        gitaar.pitchRange();
        bass.number_of_String_instrument(4);
        bass.pitchRange();
    }
    

    if (info_or_play == "play"){ 
        gitaar.play();
        gitaar.tokkelen();
        bass.play();
        bass.struming();
        trumpet.play();
        saxephone.play();
    }
    
}


