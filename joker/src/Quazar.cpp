#include "Quazar.h"
#include "Spinners.h"
#include <iostream>
#include <string>

Quazar::Quazar() {
    spin = Spinners();
    credits = 100;
    stakes = 0;
    spinValue = 0;
}

Quazar::~Quazar() {}

void Quazar::uiCalls(int choice) { //container method for UI calls
    switch (choice) {
    case 0:
        std::cout << "Welcome to Quazar!"
            "\nRules: "
            "\nTry to get as close to 20 as possible without going over."
            "\nEach turn you get to choose between 2 spinners, either: "
            "\n1) 4 - 7, or 2) 1 -8"
            "\nReady to Play?(Press Enter)" << std::endl;
        std::cin;
        break;
    case 1: {
        std::string options = "0) Exit\n1) 20 credits\n";
        //determine affordable options
        if (credits >= 100) {
            options += "2) 100 credits\n";
            if (credits >= 200) {
                options += "3) 200 credits\n";
            }
        }
        std::cout << "You currently have " << credits << " credits.\n"
            "Please enter choice for your bet:\n" << options;
        break;
    }
    case 2:
        //display spinner options
        std::cout << "Choose spinner\n"
                     "0) Stand\n"
                     "1) 1-8\n"
                     "2) 4-7\n";
        break;
    case 3:
        std::cout << "Defeat";
        break;
    case 4:
        std::cout << "Victory!";
        break;
    case 5:
        std::cout << "Play again? (Y/N)" << std::endl;
        break;
    case 6:
        std::cout << "You won " << credits << " Credits!"  << std::endl;
        break;
    case 7:
        std::cout << "You have " << credits << " credits"
        "\nInsufficient funds to Play!" << std::endl;
        break;
    case 8:
        std::cout << "You have " << credits << " credits!"
        << std::endl;
    }
}

int Quazar::input(int options) { //Ensures a valid input
    std::string in;
    std::cin >> in;
    while (!isdigit(in[0]) || (stoi(in) > options) || (stoi(in) < 0)) {
        //If in is not a digit, too big or too small, ask for a new input
        std::cout << "Please enter a digit between 0 and " << options
            << std::endl;
        std::cin >> in;
    }
    return stoi(in);
}

char Quazar::inputCh() { //ensures only Y or N is used
    std::string in;
    std::cin >> in;
    while (isdigit(in[0]) || ((in[0] != 'Y') && (in[0] != 'N'))) {
        //Ensures we get the right character input
        std::cout << "Please enter a either a 'Y' or an 'N'" << std::endl;
        std::cin >> in;
    }
    return in[0];
}

void Quazar::cashOut() {
    //calculates total cashout
    int val = (stakes == -1 ? 20 : (stakes == 0 ? 100 : 200));
    //Determines the bet value then removes it
    credits -= val;
    if (spinValue > 14 && spinValue <= 20) {
        //If between 15 and 20 it gives the correct payout
        switch (spinValue - 15) {
        case 0:
            credits += (val * 0.25);
            break;
        case 1:
            credits += (val * 0.5);
            break;
        case 2:
            credits += (val * 1);
            break;
        case 3:
            credits += (val * 1.25);
            break;
        case 4:
            credits += (val * 1.5);
            break;
        case 5:
            credits += (val * 2);
            break;
        }
    }
}

void Quazar::startGame() {
    //Start with displaying welcome message
    uiCalls(0);
    bool exitFlag = false;
    while (!exitFlag) { //Main while loop, goes until you choose N
        int c;
        int i = (credits >= 200 ? 3 : (credits >= 100 ? 2 : 1));
        uiCalls(1); //Display bet options
        c = input(i); //Only offers as many affordable options exist
        if (c == 0) break; //Exit option

        stakes = (c == 1 ? -1 : (c == 2 ? 0 : 1));
        spin.setDifficulty(stakes); //Sets difficulty modifier

        while (spinValue < 20) { //goes until you roll 20+ or stand
            int roll = 0; //Value from the current spin
            uiCalls(2);
            c = input(2);
            if (c == 0) break; //Stand

            bool b = (c == 1); //big or small spinner chosen with bool
            roll = spin.spin(b);
            spinValue += roll;

            std::cout << "You rolled a " << roll << std::endl;
            std::cout << "Your current total is " << spinValue << std::endl;
            //This part grabs the spin value, displays what you rolled and total
        }
        cashOut(); //change credits based on turn value

        if ((spinValue > 20) || (spinValue <= 14)) uiCalls(3); //loss
        else
            uiCalls(4); //victory
        if (credits < 20) { //not enough credits
            uiCalls(7);
            break;
        }
        uiCalls(8); //displays the current credits

        spinValue = 0; //Resets the spin value for replay
        uiCalls(5); //asks if you want to play again
        char x;
        x = inputCh();
        if (x == 'N') exitFlag = true;
        if (exitFlag) uiCalls(6); //exiting the game
    }
}
