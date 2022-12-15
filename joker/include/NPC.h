/**
 * @author Sarah Alibhai <sarah.alibhai@uleth.ca>
 * @date 2022-11-16
 */

#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <string>
#include <vector>

#include "Character.h"
#include "Inventory.h"
#include "Item.h"

/**
 * @class NPC NPC.h "NPC.h"
 * @brief A class for the functionality of the non-playable character
 */

class NPC : public Character {
 public:
  /**
   * @brief constructor, calls Character constructor.
   * @param[in] pcname A name for the PC.
   * @param[in] inv An inventory for the PC.
   */
  NPC(std::string pcname = "Unnamed", Inventory inv = { }) {
    setName(pcname);
    inventory = inv;
  }
  /**
   * @brief deconstructor.
   */
  ~NPC() {
  }

  void getDialogue(int event);

  void setDialogue(std::vector<std::string> option);

  /**
   * @brief adds an Item pointer to the Inventory.
   * @param[in] Found A pointer to a Item.
   */
  /**
   * @brief Actually runs the games the NPCs will play.
   * @details This will run the game the NPCs must play.
   */
  virtual void startGame() = 0;

 private:
  std::vector<std::string> options;
};

#endif
