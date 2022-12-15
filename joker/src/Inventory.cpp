/**
 * @author Ethan Kostiuk <ethan.kostiuk@uleth.ca>
 * @date 2022-11-15
 */

#include <iostream>
#include <vector>
#include <string>

#include "Inventory.h"
#include "Item.h"

Inventory::Inventory() {
  Items.clear();
}

Inventory::Inventory(std::initializer_list<Item*> i)
  :
  Items(i) {
}

Inventory::~Inventory() {
  for (Item *i : Items)
    delete i;
}

Inventory& Inventory::operator=(const Inventory &inv) {
  if (this != &inv) {
    for (Item *i : Items)
      this->removeItem(i->getName());
    Items.clear();
  }
  if (Items.empty()) {
    for (Item *i : inv.Items) {
      this->addItem(i->Clone());
    }
  }
  return *this;
}

void Inventory::addItem(Item *I) {
  Items.push_back(I);
}

const void Inventory::showInventory() const {
  if (Items.empty() == false) {
    int i = 1;
    for (Item *item : Items) {
      std::cout << i << ". " << item->getName() << std::endl;
      i++;
    }
  } else {
    std::cout << "Inventory is Empty" << std::endl;
  }
}

Item* Inventory::findItem(std::string name) {
  for (Item *item : Items)
    if (item->getName() == name)
      return item;
  std::cout << "Item cannot be found" << std::endl;
  return nullptr;
}

Item* Inventory::removeItem(std::string name) {
  Item *found = findItem(name);
  if (found != nullptr) {
    for (int i = 0; i < Items.size(); i++) {
      if (Items[i] == found) {
        Items.erase(Items.begin() + i);
        return found;
      }
    }
  }
  return found;
}

bool Inventory::isEmpty() {
  return Items.empty();
}

const bool Inventory::operator==(const Inventory &inv) const {
  if (Items.size() > inv.Items.size()) {
    std::cout << "Inventory too small" << std::endl;
    return false;
  }
  for (int i = 0; i < Items.size(); i++) {
    if ((Items[i]->getName()) != (inv.Items[i]->getName())) {
      std::cout << "Not matching" << std::endl;
      return false;
    }
  }
  return true;
}

std::vector<Item*> Inventory::getItems() {
  return Items;
}

std::string Inventory::getInteractOptions(int n) {
  if (n < Items.size() && n >= 0)
    return Items[n]->interactOptions(n);
  return "\0";
}

std::string Inventory::getInteractOptionsInv(int n) {
  if (n < Items.size() && n >= 0)
    return Items[n]->getInteractOptionsInv(n);
  return "\0";
}

const std::string Inventory::getItemName(int index) {
  if (index < Items.size() && index >= 0)
    return Items[index]->getName();
  return "Invalid Input";
}

const std::string Inventory::getItemNameChar(int index) {
  if (index < Items.size() && index >= 0)
    return Items[index]->getName();
  return "Invalid Input";
}
