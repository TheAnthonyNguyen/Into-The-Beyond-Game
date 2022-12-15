/**
 * @author Cameron Rose <c.rose@uleth.ca>
 * @date Fall 2022
 */

#include "IntoTheBeyond.h"
#include "Inventory.h"
#include "Character.h"
#include "PC.h"
#include "NPC.h"
#include "NPCRiddle.h"
#include "Environment.h"
#include "Exceptions.h"
#include "Room.h"

#include <vector>
#include <string>
#include <iomanip>
#include <typeinfo>

IntoTheBeyond::IntoTheBeyond() {
}

IntoTheBeyond::~IntoTheBeyond() {
}

void IntoTheBeyond::setEnvironments(std::vector<Environment*> environment) {
  if (!environment.empty()) {
    for (Environment *e : Environments)
      delete e;
    for (Environment *e : environment)
      Environments.push_back(e);
  }
}

std::vector<Environment*> IntoTheBeyond::getEnvironments() {
  return Environments;
}

Inventory IntoTheBeyond::searchRoom(Environment *environment) {
  return environment->getInventory();
}

void IntoTheBeyond::pickUpItem(int n, PC *you) {
  std::string name = getItemName(n, you);

  Item *found = currentRoom(you)->removeItem(name);
  if (found == nullptr)
    throw inventory_error("Item not found");
  you->pickUpItem(found);
}

void IntoTheBeyond::putDownItem(int n, PC *you) {
  std::string unwanted = getItemNameChar(n, you);

  Item *found = you->putDownItem(unwanted);
  if (found == nullptr)
    throw inventory_error("Item not found");
  currentRoom(you)->addItem(found);
}

void IntoTheBeyond::displayUI() {
  std::cout << "\nHelp(H) Exit(Q) Move(WASD)" << std::endl;
}

void IntoTheBeyond::displayHelp() {
  std::cout << "\nKey Commands\n(I): Inventory"
      << "\n(L): Look around room for items"
      << "\n(C): Look around room for characters"
      << "\n(R): Current Room you are in" << std::endl;
}

void IntoTheBeyond::displaySurroundings(PC *you) {
  std::cout << currentRoom(you)->getDesc() << std::endl;

  currentRoom(you)->displayInventory();
  std::cout << std::endl;
}
void IntoTheBeyond::displayChars(PC *you) {
  currentRoom(you)->displayCharacters();
}

int IntoTheBeyond::displaySurroundingsUI() {
  return getInput();
}

Environment* IntoTheBeyond::currentRoom(PC *you) {
  for (int i = 0; i < Environments.size(); i++)
    for (int j = 0; j < (Environments[i]->getCharacters()).size(); j++) {
      if (you->getName() == (Environments[i]->getCharacters())[j]->getName())
        return Environments[i];
    }
  throw environment_error("Couldn't find character");
  return nullptr;
}

void IntoTheBeyond::displayCurrentRoom(PC *you) {
  std::cout << currentRoom(you)->getName() << std::endl;
}

std::string IntoTheBeyond::getInteractOptions(int n, PC *Ethan) {
  return currentRoom(Ethan)->getInteractOptions(n);
}

std::string IntoTheBeyond::getInteractOptionsInv(int n, PC *Ethan) {
  return Ethan->getInteractOptionsInv(n);
}

void IntoTheBeyond::executeInteraction(int n, PC *you, std::string choice) {
  if (choice == "Pick-Up") {
    pickUpItem(n, you);
  }
  // if (choice == "getDescription")
  //std::cout <<
  //(currentRoom(you)->getInventory()).getItems()[n]->getDescription();
}

void IntoTheBeyond::executeInteractionInv(int n, PC *you, std::string choice) {
  if (choice == "Put-Down")
    putDownItem(n, you);
}

const std::string IntoTheBeyond::getItemName(int index, PC *you) {
  return currentRoom(you)->getItemName(index);
}

const std::string IntoTheBeyond::getItemNameChar(int index, PC *you) {
  return you->getItemNameChar(index);
}

void IntoTheBeyond::movePlayer(int index, PC *you) {
  currentRoom(you)->removeCharacter(you);
  Environments[index]->addCharacter(you);
  currentRoom(you)->getCharacters().pop_back();
}

int IntoTheBeyond::getInput() {
  std::string in;
  std::cout << "Chose Item(#)\nBack(0)\nChoice: ";
  std::cin >> in;
  while (!isdigit(in[0]) || (stoi(in) < 0)) {
    std::cout << "Invalid Input.\nChose Item(#)\nBack(0)\nChoice: "
        << std::endl;
    std::cin >> in;
  }
  return stoi(in);
}

void IntoTheBeyond::startGame() {
  //Initialize Cafeteria
  Duck *startDuck = new Duck(
      "Rubber Duck", "This is one of five special ducks that you can collect!");
  Duck *roomDuck = new Duck("Room Duck", "This duck is used for testing");
  Duck *blueDuck = new Duck("Blue Duck", "A gift from Crewmate Blue");

  PC *Ethan = new PC("Ethan (you)", { startDuck });
  NPCRiddle *guide = new NPCRiddle("Crewmate Blue", {blueDuck});
  std::vector<Character*> startingRoomCharacters = { Ethan, guide };

  Lock *cafLock = new Lock("CafLock", "Lock on Cafeteria", 1);

  Environment *cafeteria = new Room("Cafeteria", { roomDuck },
                                    startingRoomCharacters, "Starting Room");
  cafeteria->setLEFT("Hallway01");

  //Initialize Hallway01
  Environment *hallway01 = new Environment("Hallway01");
  hallway01->setDOWN("MedBay");
  hallway01->setLEFT("Upper Engine");
  hallway01->setRIGHT("Cafeteria");

  //Initialize Medbay
  Environment *medBay = new Room("MedBay");
  medBay->setUP("Hallway01");

  //Initialize Upper Engine
  Environment *upperEngine = new Room("Upper Engine");
  upperEngine->setDOWN("Hallway02");
  upperEngine->setRIGHT("Hallway01");

  //Initialize Hallway02
  Environment *hallway02 = new Environment("Hallway02");
  hallway02->setUP("Upper Engine");
  hallway02->setDOWN("Lower Engine");
  hallway02->setLEFT("Reactor");
  hallway02->setRIGHT("Security");

  //Initialize Reactor
  Environment *reactor = new Room("Reactor");
  reactor->setRIGHT("Hallway02");

  //Initialize Security
  Environment *security = new Room("Security");
  security->setLEFT("Hallway02");

  //Initialize Lower Engine
  Environment *lowerEngine = new Room("Lower Engine");
  lowerEngine->setUP("Hallway02");
  lowerEngine->setRIGHT("Hallway03");

  //Initialize Hallway03
  Environment *hallway03 = new Environment("Hallway03");
  hallway03->setUP("Electrical");
  hallway03->setLEFT("Lower Engine");
  hallway03->setRIGHT("Storage");

  //Initialize Electrical
  Environment *electrical = new Room("Electrical");
  electrical->setDOWN("Hallway03");

  //Initialize Storage
  Environment *storage = new Room("Storage");
  storage->setLEFT("Hallway03");
  storage->setRIGHT("Communications");
  storage->setDOWN("Faulty Airlock");

  //Initialize Communications
  Environment *communications = new Room("Communications");
  communications->setLEFT("Storage");

  //Initialize FaultyAirlock
  Environment *faultyAirlock = new Environment("Faulty Airlock");
  faultyAirlock->setUP("Storage");

  Environments = { cafeteria, hallway01, medBay, upperEngine, hallway02,
      reactor, security, lowerEngine, hallway03, electrical, storage,
      communications, faultyAirlock };

  bool quit;
  char input;

  std::cout << "Welcome to Into The Beyond!\n" << std::endl;

  do {
    displayUI();
    std::cout << "Input: ";
    std::cin >> input;
    input = toupper(input);

    switch (input) {
      case 'H':
        displayHelp();
        quit = false;
        break;
      case 'R':
        std::cout << currentRoom(Ethan)->getName() << std::endl;
        quit = false;
        break;
      case 'Q':
        quit = true;
        break;
      case 'L': {
        displaySurroundings(Ethan);
        std::string choice;
        int n = displaySurroundingsUI() - 1;
        choice = getInteractOptions(n, Ethan);
        executeInteraction(n, Ethan, choice);
        quit = false;
        break;
      }
      case 'I': {
        Ethan->displayInventory();
        int n = getInput() - 1;
        std::string choice = getInteractOptionsInv(n, Ethan);
        std::cout << choice << std::endl;
        executeInteractionInv(n, Ethan, choice);
        quit = false;
        break;
      }
      case 'W': {
        int index = 0;
        if (currentRoom(Ethan)->getUP() != "\0") {
          for (int i = 0; i < Environments.size(); i++) {
            if (Environments[i]->getName() == currentRoom(Ethan)->getUP())
              index = i;
            //Add another if here to see if room is locked
          }
          movePlayer(index, Ethan);
          displayCurrentRoom(Ethan);
          displaySurroundings(Ethan);
        }
        if (index == 0)
          std::cout << "No path this way" << std::endl;
        quit = false;
        break;
      }
      case 'A': {
        int index = 0;
        if (currentRoom(Ethan)->getLEFT() != "\0") {
          for (int i = 0; i < Environments.size(); i++) {
            if (Environments[i]->getName() == currentRoom(Ethan)->getLEFT())
              index = i;
            //Add another if here to see if room is locked
          }
          movePlayer(index, Ethan);
          displayCurrentRoom(Ethan);
          displaySurroundings(Ethan);
        }
        if (index == 0)
          std::cout << "No path this way" << std::endl;
        quit = false;
        break;
      }
        //Add another if here to see if room is locked
      case 'S': {
        int index = 0;
        if (currentRoom(Ethan)->getDOWN() != "\0") {
          for (int i = 0; i < Environments.size(); i++) {
            if (Environments[i]->getName() == currentRoom(Ethan)->getDOWN())
              index = i;
            //Add another if here to see if room is locked
          }
          movePlayer(index, Ethan);
          displayCurrentRoom(Ethan);
          displaySurroundings(Ethan);
        }
        if (index == 0)
          std::cout << "No path this way" << std::endl;
        quit = false;
        break;
      }
      case 'D': {
        int index = 0;
        if (currentRoom(Ethan)->getRIGHT() != "\0") {
          for (int i = 0; i < Environments.size(); i++) {
            if (Environments[i]->getName() == currentRoom(Ethan)->getRIGHT()) {
              //if ()
              index = i;
            }
          }
          movePlayer(index, Ethan);
          displayCurrentRoom(Ethan);
          displaySurroundings(Ethan);
        }
        if (index == 0)
          std::cout << "No path this way" << std::endl;
        quit = false;
        break;
      }
      case 'C':
        displayChars(Ethan);
        quit = false;
        break;
      default:
        std::cout << "Invalid input, try again" << std::endl;
        quit = false;
    }

    if (currentRoom(Ethan)->getName() == "Faulty Airlock") {
      std::cout << "\nYou flew out into space, and died." << std::endl;
      std::cout << "\nGAME ENDED.\n" << std::endl;
      quit = true;
    }
  } while (!quit);
}
