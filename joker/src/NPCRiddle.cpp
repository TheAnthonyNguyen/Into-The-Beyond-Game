#include "NPCRiddle.h"
#include <string>

NPCRiddle::NPCRiddle(std::string pcname, Inventory inv) {
  setName(pcname);
  inventory = inv;
}

void NPCRiddle::startGame() {
  game->startGame();
}
