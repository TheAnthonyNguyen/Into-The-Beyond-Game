/**
 * @author Cameron Rose <c.rose@uleth.ca>
 * @date Fall 2022
 */

#include <sstream>
#include <string>
#include "Item.h"
#include "gtest/gtest.h"

TEST(TestItem, constructor) {
  Duck basic;
  Duck name("Name");

  EXPECT_EQ(basic.getName(), "UnNamed");
  EXPECT_EQ(name.getName(), "Name");
}

TEST(TestItem, ducks) {
  Duck nonDuck;
  Duck redDuck("red");
  Duck doubleDuck("unchanged");

  EXPECT_EQ(nonDuck.getName(), "UnNamed");
  EXPECT_EQ(redDuck.getName(), "red");
  EXPECT_EQ(doubleDuck.getName(), "unchanged");

  doubleDuck.setName("Double");

  EXPECT_EQ(doubleDuck.getName(), "Double");
}

TEST(TestItem , comparison) {
  Duck item1;
  Duck item2;

  Duck named("Named");
  Duck named2("Named");

  EXPECT_TRUE(item1 == item2);
  EXPECT_TRUE(named == named2);
  EXPECT_FALSE(item1 == named);
}
