/**
 * @author Cameron Rose <c.rose@uleth.ca>
 * @date Fall 2022
 */

#include <sstream>
#include <string>
#include "Inventory.h"
#include "gtest/gtest.h"

TEST(TestInventory, constructor) {
  Inventory inv;

  EXPECT_TRUE(inv.isEmpty());

  Duck *d = new Duck("Duck");

  inv.addItem(d);

  EXPECT_FALSE(inv.isEmpty());

  Item *i1 = new Duck;

  Inventory inv2({ i1 });

  EXPECT_EQ(inv2.findItem("UnNamed"), i1);
}

TEST(TestInventory, findAndRemove) {
  Inventory inv;

  Duck *d = new Duck("Duck");
  inv.addItem(d);

  EXPECT_EQ(inv.findItem("Duck"), d);

  EXPECT_EQ(inv.removeItem("Duck"), d);

  EXPECT_TRUE(inv.isEmpty());

  delete d;
}

TEST(TestInventory, showInventory) {
  Inventory inv;

  Duck *d = new Duck("Duck");
  Duck *d2 = new Duck("Duck 2");
  Duck *d3 = new Duck("Duck 3");
  inv.addItem(d);
  inv.addItem(d2);
  inv.addItem(d3);

  inv.showInventory();
}

TEST(TestInventory, comparison) {
  Inventory inv;

  Item *i = new Duck;
  Item *i1 = new Duck("Named");
  Item *i2 = new Duck;
  Item *i3 = new Duck("Named");

  inv.addItem(i);
  inv.addItem(i1);

  Inventory inv2({ i2, i3 });

  EXPECT_TRUE(inv == inv2);

  inv2 = inv;

  EXPECT_TRUE(inv == inv2);

  delete i2;
  delete i3;
}

