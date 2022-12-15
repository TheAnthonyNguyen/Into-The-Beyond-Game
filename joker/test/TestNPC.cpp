#include <string>
#include <vector>
#include <iostream>

#include "NPC.h"
#include "NPCQuazar.h"
#include "NPCRiddle.h"
#include "Lock.h"
#include "gtest/gtest.h"

TEST(TestNPC, constructor) {
  Key *k = new Key;

  NPCRiddle n1;
  NPCRiddle n2("Dr.Anvik", { k });
  NPCRiddle n3("Changable Name");

  EXPECT_EQ(n1.getName(), "Unnamed");
  EXPECT_EQ(n2.getName(), "Dr.Anvik");
  EXPECT_EQ(n3.getName(), "Changable Name");

  n3.setName("Nicole Wilson");

  EXPECT_EQ(n3.getName(), "Nicole Wilson");
}

TEST(TestNPC, dialoge) {
  NPCRiddle d;
  std::vector<std::string> dumb = {"Hello", "Goodbye"};

  d.setDialogue(dumb);

  d.getDialogue(0);
  d.getDialogue(1);
}
