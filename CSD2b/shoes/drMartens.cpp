#include <iostream>
#include "drMartens.h"


drMartens::drMartens(std::string shoes) : Shoes(shoes){
    std::cout << "this pair" << shoes << "\n";
}

drMartens::~drMartens(){
}
