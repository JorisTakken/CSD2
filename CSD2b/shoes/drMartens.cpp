#include <iostream>
#include "drMartens.h"



drMartens::drMartens(std::string shoes) : Shoes(shoes){
    std::cout << "this pair" << shoes << "\n";
}

drMartens::~drMartens(){
}

void drMartens::lether(){
    std::cout << "you choose lether so you have a drMartens shoe now!" << "\n";

}