#ifndef QUAZAR_GAME
#define QUAZAR_GAME
#include "Spinners.h"

class Quazar{ //Game engine
 public:
    Quazar(); //Builds the spinner and sets default values
    ~Quazar(); //Added for habit forming
    void startGame(); //Starts the game
 private:
    void uiCalls(int choice); //Holds all UI strings
    int input(int options); //Ensures a good int input value
    char inputCh(); //Ensures a good char input value
    void cashOut(); //Handles credit changes after each turn

    int credits; //Holds credit value
    int stakes; //Represents the bet level
    int spinValue; //Holds combined spin value
    Spinners spin; //Holds a spin
};
#endif //QUAZAR_GAME
