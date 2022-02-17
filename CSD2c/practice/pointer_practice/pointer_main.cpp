#include <iostream>
#include <math.h>

float wortel(float input, float *wortel_1, float *wortel_2){
    // ik doe geen return maar toch staan de wortels opgeslagen!
    // dat is het handige van pointers

    *wortel_1 = sqrt(input);
    *wortel_2 = -1 * *wortel_1;
}

int main(){

    float getal = 100;
    char* letter; 
    
    letter = (char* ) &getal; 
    std::cout << letter << std::endl; 


    float wortelPlus, wortelMin;
    float welkeWortel = 49;

    wortel(welkeWortel,&wortelPlus,&wortelMin);
    // std::cout << wortelPlus <<  "wortel" << std::endl; 
    // std::cout << wortelMin <<  "wortel" << std::endl; 

    float* test;
    test = &getal;
    std::cout << *test  <<  " test" << std::endl; 

    
}



