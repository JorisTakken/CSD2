#include <iostream>
#include "strings.h"
#include "play_and_info.h"
#include "wind_instrument.h"


// stinginstruments
// struming();
// tokkelen();
// number_of_String_instrument(int number_of_String_instrument);



int main(){
    // String_instrument gitaar("<gitaar>","82.41Hz , 329.63Hz");
    // String_instrument bass("<bass>","60Hz , 250Hz");
    // Wind_instrument trumpet("<trumpet>","164.8Hz , 932.3Hz");
    // Wind_instrument saxephone("<saxephone>","138Hz , 830Hz");

    
    All_instruments gitaar("<gitaar>","82.41Hz , 329.63Hz");
    All_instruments bass("<bass>","60Hz , 250Hz");

    All_instruments trumpet("<trumpet>","164.8Hz , 932.3Hz");
    All_instruments saxephone("<saxephone>","138Hz , 830Hz");


    gitaar.play_string("strum");
    bass.play_string("tokkel");
    saxephone.play_wind();
    trumpet.play_wind();



    saxephone.info_wind("mid");
    trumpet.info_wind("low");

    bass.info_string(4);
    gitaar.info_string(6);













    // std::string info_or_play; 
    // std::cout << "would you like to play the instrument or know information about them?" << "\n";
    // std::cout << "(info) (play)" << "\n";


    // std::cin >> info_or_play;
    // std::cout << info_or_play << "\n";


    // if (info_or_play == "info"){ 
    //     saxephone.place_in_spectrum("mid");
    //     saxephone.pitchRange();
    //     trumpet.place_in_spectrum("high");
    //     trumpet.pitchRange();
    //     gitaar.number_of_String_instrument(6);
    //     gitaar.pitchRange();
    //     bass.number_of_String_instrument(4);
    //     bass.pitchRange();
    // }
    

    // if (info_or_play == "play"){ 
    //     gitaar.play_ins();
    //     gitaar.tokkelen();
    //     bass.play_ins();
    //     bass.struming();
    //     trumpet.play_ins();
    //     saxephone.play_ins();
    // }
    
}


