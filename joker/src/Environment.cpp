/**
 * @author Anthony Nguyen <anthony.nguyen2@uleth.ca>
 * @date Fall 2022
 */

#include "Environment.h"
#include <iostream>
#include <vector>
#include <string>

Environment::Environment(std::string name, Inventory inv,
                         std::vector<Character*> characters, std::string desc) {
  this->name = name;
  inventory = inv;
  setCharacters(characters);
  this->desc = desc;
  this->UP = "\0";
  this->LEFT = "\0";
  this->DOWN = "\0";
  this->RIGHT = "\0";
}

Environment::~Environment() {
  for (auto c1 : characters)
    delete c1;
  characters.clear();
}
/*
 void Environment::setConnections(std::vector<Environment*> Connections) {
 for (auto c : Connections)
 connections.push_back(c);
 }
 */
void Environment::setCharacters(std::vector<Character*> Characters) {
  for (auto c : Characters)
    characters.push_back(c);
}

std::string Environment::getName() {
  return name;
}
/*
 std::vector<Environment*> Environment::getConnections() {
 return connections;
 }
 */
std::vector<Character*> Environment::getCharacters() {
  return characters;
}

bool Environment::getPC() {
  return true;
}

void Environment::togglePC() {
  pcPresent = !pcPresent;
}

void Environment::addCharacter(Character *ch) {
  if (ch != nullptr)
    characters.push_back(ch);
}

void Environment::addItem(Item *it) {
  if (it != nullptr)
    inventory.addItem(it);
}
/*
 void Environment::addConnection(Environment *en) {
 if (en != nullptr)
 connections.push_back(en);
 }
 */
void Environment::removeCharacter(Character *ch) {
  for (int i = 0; i < characters.size(); i++) {
    if (characters[i] == ch)
      characters.erase(characters.begin() + i);
  }
}

Item* Environment::removeItem(std::string name) {
  return inventory.removeItem(name);
}
/*
 void Environment::removeConnection(Environment *en) {
 for (int i = 0; i < connections.size(); i++) {
 if (connections[i] == en)
 connections.erase(connections.begin() + i);
 }
 }
 */
void Environment::setInventory(Inventory inv) {
  this->inventory = inv;
}

Inventory Environment::getInventory() {
  return inventory;
}

std::string Environment::getUP() {
  return UP;
}
std::string Environment::getLEFT() {
  return LEFT;
}
std::string Environment::getDOWN() {
  return DOWN;
}
std::string Environment::getRIGHT() {
  return RIGHT;
}

void Environment::setUP(std::string s) {
  UP = s;
}
void Environment::setLEFT(std::string s) {
  LEFT = s;
}
void Environment::setDOWN(std::string s) {
  DOWN = s;
}
void Environment::setRIGHT(std::string s) {
  RIGHT = s;
}

void Environment::displayInventory() {
  inventory.showInventory();
}

void Environment::displayCharacters() {
  int k = 0;
  for (int i = 0; i < characters.size(); i++) {
    k++;
    std::cout << k << ". " << characters[i]->getName() << std::endl;
  }
}

std::string Environment::getInteractOptions(int i) {
  return inventory.getInteractOptions(i);
}

const std::string Environment::getItemName(int index) {
  return inventory.getItemName(index);
}

void Environment::setDesc(std::string d) {
  desc = d;
}

const std::string Environment::getDesc() {
  return desc;
}
