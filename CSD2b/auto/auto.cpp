#include <iostream>

class Seats{
public:
    Seats();
    ~Seats();
    void printSeatWarmth(float seat_warmth);
};

Seats::Seats(){
}
Seats::~Seats(){
}

void Seats::printSeatWarmth(float seat_warmth) {
    std::cout << "seat_warmth   " << seat_warmth << std:: endl;
}




class Wheel {
public:
    Wheel();
    ~Wheel();
    void printWheelWidth(float wheel_width);
};

Wheel::Wheel() 
{
}

Wheel::~Wheel()
{    
}

void Wheel::printWheelWidth(float wheel_width) {
    std::cout << "wheel_width   " << wheel_width << std:: endl;
}







class Car{
public:
    Car();
    ~Car();
    Wheel leftFront;
    Wheel leftBack;
    Wheel rightFront;
    Wheel rightBack;


    Seats seat1;
    Seats seat2;
    Seats seat3;
    Seats seat4;
    void print_variables();
};

Car::Car(){
    
}
Car::~Car(){
}

void Car::print_variables(){
    leftFront.printWheelWidth(10.2);
    leftBack.printWheelWidth(54.4);
    rightFront.printWheelWidth(24.2);
    rightBack.printWheelWidth(44.9);

    
    seat1.printSeatWarmth(20);
    seat2.printSeatWarmth(23);
    seat3.printSeatWarmth(21);
    seat4.printSeatWarmth(19);  
}


int main(){   
    Car car1;

    car1.print_variables();
    
    
    
}