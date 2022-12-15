/**
 * @author Cameron Rose <c.rose@uleth.ca>
 * @date 2022-12-07
 */

#ifndef NPCQUAZAR_H
#define NPCQUAZAR_H

#include <string>
#include <iostream>

#include "Character.h"
#include "NPC.h"
#include "Quazar.h"

/**
 * @class NPCQuazar NPCQuazar.h "NPCQuazar.h"
 * @brief A class that contains the NPC that makes you play Quazar
 */
class NPCQuazar : public NPC {
 public:
  /**
   * @brief default constructor.
   */
  NPCQuazar(std::string pcname = "Unnamed", Inventory inv = { })
      :
      NPC(pcname, inv) {
  }

  /**
   * @brief destructor.
   */
  ~NPCQuazar() {
  }

  /**
   * @brief starts playing Quazar
   */
  void startGame();

 private:
  /**
   * @brief an instance of the Quazar game
   */
  Quazar game;
};

#endif //NPCQUAZAR_H
