/**
 * @author Sarah Alibhai <sarah.alibhai@uleth.ca>
 * @date 2022-11-17
*/

#include <iostream>
#include <string>
#include <vector>

#include "NPC.h"
#include "Inventory.h"

void NPC::getDialogue(int event) {
  std::cout << options[event] << std::endl;
}

void NPC::setDialogue(std::vector<std::string> option) {
  for (std::string s : option)
    options.push_back(s);
}
