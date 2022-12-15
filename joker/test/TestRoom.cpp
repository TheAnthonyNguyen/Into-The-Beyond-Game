#include <vector>

#include "Environment.h"
#include "Character.h"
#include "gtest/gtest.h"
#include "PC.h"
#include "Room.h"
#include "Item.h"
#include "Inventory.h"

TEST(TestRoom, defaultConstructor) {
  Room *empty = new Room;
  Inventory inv;
  std::vector<Character*> c = {};

  EXPECT_EQ(empty->getName(), "Empty");
  EXPECT_EQ(empty->getInventory(), inv);
  EXPECT_EQ(empty->getCharacters(), c);
  EXPECT_EQ(empty->getDesc(), "Basic Room");
  EXPECT_EQ(empty->getLock(), nullptr);

  EXPECT_EQ(empty->getUP(), "\0");
  EXPECT_EQ(empty->getLEFT(), "\0");
  EXPECT_EQ(empty->getDOWN(), "\0");
  EXPECT_EQ(empty->getRIGHT(), "\0");

  delete empty;
}

TEST(TestRoom, Constructor) {
  Duck *flask = new Duck("Erlenmeyer Flask");
  Duck *blue = new Duck("Meth duck", "Jesse! Why are you blue?");

  PC *walter = new PC("Walter White");
  Character *jesse = new Character("Jesse Pinkman");
  std::vector<Character*> BBCast = {walter, jesse};

  Lock *tape = new Lock("RV Door Lock");

  Room *rv = new Room("Meth RV", {flask, blue}, BBCast,
  "This is my own private domicile and I will not be harassed...B*tch", tape);

  EXPECT_EQ(rv->getName(), "Meth RV");

  EXPECT_EQ(rv->getDesc(),
  "This is my own private domicile and I will not be harassed...B*tch");
  rv->setDesc("RV with bullet holes in door");
  EXPECT_EQ(rv->getDesc(), "RV with bullet holes in door");

  EXPECT_EQ(rv->getCharacters(), BBCast);

  std::cout << "RV Room items: " << std::endl;
  rv->displayInventory();

  std::cout << "RV Room Characters: " << std::endl;
  rv->displayCharacters();

  EXPECT_EQ(rv->getLock(), tape);
  EXPECT_EQ(rv->lockStatus(), true);

  delete rv;
}
