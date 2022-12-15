/**
 * @author Sarah Alibhai <sarah.alibhai@uleth.ca>
 * @date 2022-11-17
*/

#include <iostream>
#include <string>

#include "PC.h"
#include "Inventory.h"

PC::PC(std::string name, Inventory inv) {
  setName(name);
  inventory = inv;
}

void PC::pickUpItem(Item *found) {
  inventory.addItem(found);
}

Item* PC::putDownItem(std::string name) {
  return inventory.removeItem(name);
}

std::string PC::getInteractOptionsInv(int n) {
  return inventory.getInteractOptionsInv(n);
}

const std::string PC::getItemNameChar(int index) {
  return inventory.getItemNameChar(index);
}
