/**
 * @author Ethan Kostiuk <ethan.kostiuk@uleth.ca>
 * @date 2022-11-15
 */

#include <iostream>
#include <string>

#include "Item.h"

Item::Item(std::string name) {
  setName(name);
}

Item::Item(const Item &copy) {
  setName(copy.name);
}

std::string Item::interactOptions(int c) {
  std::cout << "This item has no options" << std::endl;
  return "";
}

std::string Item::getInteractOptionsInv(int c) {
  std::cout << "This function should not be called" << std::endl;
  return "";
}

void Item::setName(std::string n) {
  name = n;
}

const std::string Item::getName() const {
  return name;
}

bool Item::operator==(const Item &item) {
  return (this->getName() == item.getName());
}

Duck::Duck() {
  description = "Boring Duck";
}

Duck::Duck(const Duck &copy)
    :
    Item(copy.getName()) {
  description = copy.description;
}

std::string Duck::getDescription() {
  return description;
}

std::string Duck::interactOptions(int c) {
  std::string in;
  std::cout << "Read description of duck(1)\nPick-up(2)\nChoice: ";
  std::cin >> in;
  while (!isdigit(in[0]) || (stoi(in) < 0)) {
    std::cout << "Read description of duck(1)\nPick-up(2)\nChoice: "
        << std::endl;
    std::cin >> in;
  }
  c = stoi(in);

  if (c == 0) {
    return "\0";
  }
  if (c == 1) {
    std::cout << getDescription() << std::endl;
    return "";
  }
  if (c == 2) {
    return "Pick-Up";
  } else {
    std::cout << "Invalid input" << std::endl;
    return "";
  }
}

std::string Duck::getInteractOptionsInv(int c) {
  std::string in;
  std::cout << "Read description of duck(1)\nPut-Down(2)\nChoice: ";
  std::cin >> in;
  while (!isdigit(in[0]) || (stoi(in) < 0)) {
    std::cout << "Read description of duck(1)\nPut-Down(2)\nChoice: "
        << std::endl;
    std::cin >> in;
  }
  c = stoi(in);

  if (c == 0) {
    return "\0";
  }
  if (c == 1) {
    std::cout << getDescription() << std::endl;
    return "";
  }
  if (c == 2) {
    return "Put-Down";
  } else {
    std::cout << "Invalid input" << std::endl;
    return "";
  }
}
