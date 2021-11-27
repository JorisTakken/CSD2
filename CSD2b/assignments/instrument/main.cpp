#include <iostream>
#include "strings.h"

// stinginstruments
// struming();
// tokkelen();
// number_of_String_instrument(int number_of_String_instrument);

int main(){
    String_instrument gitaar("gitaar");
    String_instrument bass("bass");

    gitaar.play();
    gitaar.tokkelen();
    gitaar.number_of_String_instrument(6);

    bass.play();
    bass.struming();
    bass.number_of_String_instrument(4);


}