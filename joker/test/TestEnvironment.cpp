/**
 * @author Ethan Kostiuk <ethan.kostiuk@uleth.ca>
 * @date 2022-12-2
 */
#include <vector>

#include "Environment.h"
#include "Character.h"
#include "gtest/gtest.h"
#include "PC.h"

TEST(TestEnvironment, defaultConstructor) {
  Environment *empty = new Environment;
  Inventory inv;
  std::vector<Character*> c = { };

  EXPECT_EQ(empty->getName(), "Empty");
  EXPECT_EQ(empty->getInventory(), inv);
  EXPECT_EQ(empty->getCharacters(), c);

  EXPECT_EQ(empty->getUP(), "\0");
  EXPECT_EQ(empty->getLEFT(), "\0");
  EXPECT_EQ(empty->getDOWN(), "\0");
  EXPECT_EQ(empty->getRIGHT(), "\0");

  delete empty;
}

TEST(TestEnvironment, constructor) {
  Duck *redDuck = new Duck("Red Duck", "Description of red");
  Duck *orangeDuck = new Duck("Orange Duck", "Description of orange");
  Duck *yellowDuck = new Duck("Yellow Duck", "Description of yellow");
  Duck *roomDuck = new Duck("Room Duck", "Cooks meth");

  PC *Ethan = new PC("Ethan", { redDuck, orangeDuck, yellowDuck });
  Character *Gus = new Character;

  std::vector<Character*> cafChars = { Ethan, Gus };

  Environment *cafeteria = new Environment("Cafeteria", { roomDuck }, cafChars);

  EXPECT_EQ(cafeteria->getName(), "Cafeteria");

  cafeteria->displayInventory();
  cafeteria->displayCharacters();

  PC *jesse = new PC("Jesse");

  cafeteria->addCharacter(jesse);

  std::cout << "Added Character\n";
  cafeteria->displayCharacters();

  cafeteria->removeCharacter(Gus);

  std::cout << "Removed Character\n";
  cafeteria->displayCharacters();

  delete cafeteria;
  delete Gus;
}

TEST(TestEnvironment, envItems) {
  Duck *testDuck = new Duck("Test Duck", "This is a description");

  Environment *room = new Environment("Test Room", { }, { });

  room->addItem(testDuck);

  std::cout << "Added Item\n";
  room->displayInventory();

  std::cout << "Removed Item\n";
  room->removeItem("Test Duck");
  room->displayInventory();

  delete room;
  delete testDuck;
}

TEST(TestEnvironment, connections) {
  Environment *room = new Environment("Test Room");

  room->setUP("Room above");
  room->setLEFT("Room left");
  room->setDOWN("Room below");
  room->setRIGHT("Room right");

  EXPECT_EQ(room->getUP(), "Room above");
  EXPECT_EQ(room->getLEFT(), "Room left");
  EXPECT_EQ(room->getDOWN(), "Room below");
  EXPECT_EQ(room->getRIGHT(), "Room right");

  delete room;
}
