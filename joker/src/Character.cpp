/**
 * @author Sarah Alibhai <sarah.alibhai@uleth.ca>
 * @date 2022-11-16
*/

#include <iostream>
#include <string>

#include "Character.h"
#include "Inventory.h"

Character::Character(std::string name, Inventory bag) {
  setName(name);
  inventory = bag;
}

void Character::setName(std::string n) {
  name = n;
}

std::string Character::getName() {
  return name;
}

Inventory Character::getInventory() {
  return inventory;
}

const void Character::displayInventory() const {
  inventory.showInventory();
}
