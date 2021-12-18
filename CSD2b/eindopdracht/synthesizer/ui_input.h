#include <iostream>

#pragma once

class User_input{
    public:
        User_input();
        ~User_input();  

        // if there is nothing wrong witch input selection, return input
        std::string make_userSelection(std::string selectionOptions[], int numOptions);
        // if user coise is not in array :say "wrong input"
        bool validateSelection(std::string selection, std::string selectionOptions[],int numOptions);
        std::string retrieveUserInput(std::string selectionOptions[], int numOptions);

        float user_input_numbers(float min, float max);


    protected:
        // std::string selectionOptions[];
        int numOptions;
        std::string selection;
        
};

