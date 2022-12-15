/**
 * @author Anthony Nguyen <anthony.nguyen2@uleth.ca>
 * @date 2022-12-07
 */

#ifndef NPCRIDDLE_H
#define NPCRIDDLE_H

#include "Character.h"
#include "NPC.h"

#include <string>
#include <iostream>
#include <vector>

/**
 * @class NPCRiddle NPCRiddle.h "NPCRiddle.h"
 * @brief A class that contains the NPC that makes you do a riddle
 */
class NPCRiddle : public NPC {
 public:
  /**
   * @brief default constructor.
   */
  NPCRiddle(std::string pcname = "Unnamed", Inventory inv = { });

  /**
   * @brief destructor.
   */
  ~NPCRiddle() {
  }

  /**
   * @brief starts the riddle
   */
  void startGame();

 private:
  NPC *game;
};

#endif //NPCRIDDLE_H
