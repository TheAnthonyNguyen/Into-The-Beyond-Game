/**
 * @author Cameron Rose <c.rose@uleth.ca>,
 * @author Ethan Kostiuk <ethan.kostiuk@uleth.ca>
 * @date Fall 2022
 */

#include <sstream>
#include <string>

#include "Character.h"
#include "PC.h"
#include "Inventory.h"
#include "Item.h"
#include "gtest/gtest.h"

TEST(TestCharacter, defaultConstructor) {
  Character empty;
  Inventory inv;

  EXPECT_EQ(empty.getName(), "Unnamed");
  EXPECT_EQ(empty.getInventory(), inv);
}
TEST(TestCharacter, constructor) {
  Duck *redDuck = new Duck("Red Duck", "Description of red");
  Duck *orangeDuck = new Duck("Orange Duck", "Description of orange");
  Duck *yellowDuck = new Duck("Yellow Duck", "Description of yellow");

  Character Ethan("Ethan", {redDuck, orangeDuck, yellowDuck});

  EXPECT_EQ(Ethan.getName(), "Ethan");

  Ethan.displayInventory();
//  Ethan.getInventory().showInventory(); //  Don't do this, causes headache
  Ethan.setName("Walter White");

  EXPECT_EQ(Ethan.getName(), "Walter White");
}
TEST(TestPC, defaultConstructor) {
  PC *empty = new PC;
  Inventory inv;

  EXPECT_EQ(empty->getName(), "Unnamed");
  EXPECT_EQ(empty->getInventory(), inv);

  delete empty;
}
TEST(TestPC, constructor) {
  Duck *redDuck = new Duck("Red Duck", "Description of red");
  Duck *orangeDuck = new Duck("Orange Duck", "Description of orange");
  Duck *yellowDuck = new Duck("Yellow Duck", "Description of yellow");

  PC *Ethan = new PC("Ethan", {redDuck, orangeDuck, yellowDuck});

  EXPECT_EQ(Ethan->getName(), "Ethan");

  Ethan->displayInventory();
  Ethan->setName("Walter White");

  EXPECT_EQ(Ethan->getName(), "Walter White");

  delete Ethan;
}
