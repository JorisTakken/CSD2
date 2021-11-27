#include <iostream> 
#include "shoes.h"



class drMartens : public Shoes
{
public: 
    drMartens(std::string shoes);
    ~drMartens();

    void lether();
}; 