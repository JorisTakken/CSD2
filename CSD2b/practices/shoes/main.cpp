#include <iostream>
#include "drMartens.h"
#include "vans.h"




// overeenkomsten
    // ze hebben feters
    // ze hebben zolen
    // je kan erop lopen

// verschillen 
    // kleur

int main(){
    drMartens martens("pair1");
    Vans vans;


    std::cout << "Make your own shoe!" << "\n";
    std::cout << "typ in the first component" << "\n";

    std::string choise_input_user; 
    std::cin >> choise_input_user; 
    std::cout << choise_input_user << "\n";
    if (choise_input_user == "laces"){martens.laces();}
    else if (choise_input_user == "soles"){martens.soles();}
    else{std::cout << "Thats no component for a shoe? weirdo" << "\n";}

    std::cout << "-" << "\n";
    std::cout << "what matrial is your shoe?" << "\n";
    std::string choise_input_user; 
    std::cin >> choise_input_user; 
    std::cout << choise_input_user << "\n";
    if (choise_input_user == "stof"){
        vans.stof();
    }
    if (choise_input_user == "lether"){
        martens.lether();
    }
}