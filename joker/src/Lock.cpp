/**
 * @author Sarah Alibhai <sarah.alibhai@uleth.ca>
 * @date 2022-12-04
 */

#include <iostream>
#include <string>

#include "Lock.h"

Key::Key() {
  description = "Shapeless Floating";
  ID = 0;
}

Key::Key(const Key &copy)
    :
    Item(copy.getName()) {
  description = copy.description;
  ID = copy.ID;
}

void Key::setID(int num) {
  ID = num;
}

int Key::getID() {
  return ID;
}

void Key::setDescription(std::string adjective) {
  description = adjective;
}

std::string Key::getDescription() {
  return description;
}

Lock::Lock() {
  use = "Currently Useless";
  ID = 0;
}

Lock::Lock(const Lock &copy)
    :
    Item(copy.getName()) {
  use = copy.use;
  ID = copy.ID;
}

void Lock::setID(int num) {
  ID = num;
}

int Lock::getID() {
  return ID;
}

void Lock::setUse(std::string purpose) {
  use = purpose;
}

std::string Lock::getUse() {
  return use;
}

bool Lock::pair(Key *thisKey) {
  if (ID == thisKey->getID())
    return true;
  else
    return false;
}
