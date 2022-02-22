// #include "sine"
#include <iostream>
#define steps 5

float nearestNabour(float input, float min, float max){
    float value;
    if (input < 0.5){
        value = min;
    }else {
        value = max;
    }
    return value;
}   

float inRange(float input, int x1, int x2 , float min, float max){
    // STARTING AT A X VALUE
    float value = (min * (x2 - input) + max * (input - x1)) / (x2 - x1);    
    return value;
}

float liniairInterlopation(float input, float min, float max){
    // // STARTING AT 0
    // float value;
    // float range = max - min; 
    // value = range * input;
    // value += min;
    float value = inRange(input, 0, 1, min, max);
    return value;
}






int main(){ 
    std::cout << "NEAREST NABOUR!" << std::endl;
    std::cout << "---------------" << std::endl;
    for (int i = 0; i < steps; i++) {
        float input = (float)i / steps;
        float out = nearestNabour(input,4,7);
        std::cout << input <<  "   lekker   " << out << std::endl;
    }

    std::cout << "LINIAIR INTERPOL!" << std::endl;
    std::cout << "---------------" << std::endl;
    for (int i = 0; i < steps; i++) {
        float input = (float)i / steps;
        float out = liniairInterlopation(input,100,200);
        std::cout << input <<  "   lekker   " << out << std::endl;
    }

    std::cout << "LINIAIR INTERPOL IN RANGE!" << std::endl;
    std::cout << "---------------" << std::endl;
    for (int i = 0; i < steps; i++) {
        float input = 1.0 + (float)i / steps;
        float out = inRange(input,1,2,100,200);
        std::cout << input <<  "   lekker   " << out << std::endl;
    }
}


