#include "Room.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

Room::Room(std::string name, Inventory inv, std::vector<Character*> characters,
           std::string desc, Lock *lock) {
  this->name = name;
  inventory = inv;
  setCharacters(characters);
  this->UP = "\0";
  this->LEFT = "\0";
  this->DOWN = "\0";
  this->RIGHT = "\0";
  this->desc = desc;
  this->lock = lock;
}

void Room::setLock(Lock *locks) {
  lock = locks;
}

bool Room::getLocked(Key *keys) {
  if (lock->pair(keys))
    locked = false;
  return locked;
}

void Room::LockRoom() {
  locked = true;
}

bool Room::lockStatus() {
  return locked;
}
Lock* Room::getLock() {
  return lock;
}

std::string Room::getDesc() {
  return desc;
}

void Room::setDesc(std::string s) {
  desc = s;
}
