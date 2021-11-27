#include <iostream>
#include "bike.h"

Bike::Bike(){
}

Bike::~Bike(){
}

void Bike::bike_defect(std::string wrong_with_bike){
    std::cout << "Whats wrong with your bike?" << wrong_with_bike << std:: endl;
}