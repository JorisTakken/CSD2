#include <iostream>
#include "shoes.h"

Shoes::Shoes(std::string shoes) {
    std::cout << "This shoe is pear : "<< shoes << "\n";
    this->shoes = shoes;
}

Shoes::~Shoes(){
}


void Shoes::laces(){
  std::cout << shoes << ": has laces now! " << "\n";

}

void Shoes::soles(){
  std::cout << shoes << ": has soles now! " << "\n";
}   