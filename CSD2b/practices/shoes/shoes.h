#pragma once
#include <iostream> 

class Shoes{
public: 
    Shoes(std::string shoes);
    ~Shoes();

    void laces();
    void soles();

protected:
  std::string shoes;
}; 