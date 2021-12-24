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

void User_input::userInitializeFMsynth(){
  // ------------------------------------------------------------------
  // initialise FM synth, give waveform and ratio for modulator and carrier
  // ------------------------------------------------------------------
  std::string waveOptions[3] = {"saw","sine","square"};

  std::cout << "choose waveform carrier : " << std::endl;
  std::string waveFormCar = make_userSelection(waveOptions, 3);
  this->waveFormCar = waveFormCar;

  std::cout << "choose waveform modulator : " << std::endl;
  std::string waveFormMod = make_userSelection(waveOptions, 3);
  this->waveFormMod = waveFormMod; 

  std::cout << "choose ratio : " << std::endl;
  float ratio = user_input_numbers(0,40);
  this->ratio = ratio;

  std::cout << "choose modulaton depth : " << std::endl;
  float modDepth = user_input_numbers(0,1000);
  this->modDepth = modDepth;

}

std::string User_input::getWaveFormCar(){
  return waveFormCar;
}

std::string User_input::getwaveFormMod(){
  return waveFormMod;
}

float User_input::getRatio(){
  return ratio;
}

float User_input::getModDepth(){
  return modDepth;
}




void User_input::userInitializeWavetable(int numberOfOscillators){
  // ------------------------------------------------------------------
  // initialise wavetable, give waveform and pitch for every oscilator
  // ------------------------------------------------------------------
    std::string waveOptions[3] = {"saw","sine","square"};
    // std::string waveforms[] = {};
    // int midipitches[] = {};

    this->waveforms[numberOfOscillators] = waveforms[numberOfOscillators]; 
    this->midipitches[numberOfOscillators] = midipitches[numberOfOscillators]; 
    this->numberOfOscillators = numberOfOscillators;

    for (int i = 0; i < numberOfOscillators; i++){
      std::cout << "choose waveform for oscillator number : " << i + 1 <<  std::endl;
      waveforms[i] = make_userSelection(waveOptions,3);
      std::cout << "choose midipitch for oscillator number : " << i + 1 <<  std::endl;
      midipitches[i] = user_input_numbers(0,127);
    }    
    
}

std::string User_input::getWaveforms(int next){
  return this->waveforms[next];
}

int User_input::getMidiPitches(int next){
  return this->midipitches[next];
}

int User_input::getNumberOfOscillators(){
  return numberOfOscillators;
}

