#include <iostream>
#include "car.h"

Car::Car(){
}

Car::~Car(){
}

void Car::Car_defect(std::string wrong_with_car){
    std::cout << "Whats wrong with your car?" << wrong_with_car << std:: endl;
}