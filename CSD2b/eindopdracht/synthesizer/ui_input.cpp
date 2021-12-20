#include "ui_input.h"


User_input::User_input(){
}

User_input::~User_input(){
}

std::string User_input::make_userSelection(std::string options_selection[], int number_options){
    bool noCorrectSelection = true;
    std::string userSelection;

    // while loop becouse, if answare is not a possibillity, choose an other one entil a right asware is chosen.
    // as long as noCorrectSelection == true --> keep trying
    while(noCorrectSelection) {

        // let user choose 1 of the options given
        userSelection = retrieveUserInput(options_selection,number_options);

        // validate input! 
        noCorrectSelection = !validateSelection(userSelection, options_selection,number_options);

        // if selection is not correct, try again
        if(noCorrectSelection) {
            std::cout << "Incorrect selection, please try again";
        }
    }
    return userSelection;
}

bool User_input::validateSelection(std::string selection, std::string options_selection[],int number_options){

    // check of input is one of the options
    for (int i = 0; i < number_options; ++i) {
        if(selection == options_selection[i]) {
            return true;
        }
    }
    // selection is not in options --> return false
    return false;
}

std::string User_input::retrieveUserInput(std::string options_selection[], int number_options){

    // show all options you can choose from
    std::cout << "Please enter your selection. You can choice between: ";
    for(int i = 0; i < number_options - 1; i++) {
        std::cout << options_selection[i] << ", ";
    }

    // print last option outside forloop to end with an .
    std::cout << options_selection[number_options - 1] << "." << std::endl;

    // retrieve and return choice
    std::string selection = "";
    std::cin >> selection;
    return selection;
}

int User_input::user_input_numbers(int min, int max){
  std::string input;
  int value = 0;
  bool notInRange = true;

  while(notInRange) {
    std::cout << "Please enter a value between " << min << " and " << max
      << std::endl;
    // first capture input in input string
    std::cin >> input;
    // validate if input string can be transformed into a int
    try {
      value = std::stof(input);
      // validate range
      if(value >= min && value <= max) {
        notInRange = false;
      } else {
        // value not in range
        std::cout << "Incorrect range, please try again." << std::endl;
      }
    } catch (const std::exception& e) {
      // no int as input
      std::cout << "Invalid input, this was not a number, please try again"
        << std::endl;
    }
  }

  return value;
}