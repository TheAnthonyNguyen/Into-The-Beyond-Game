/**
 * @author Sarah Alibhai <sarah.alibhai@uleth.ca>
 * @date 2022-11-16
 */

#ifndef PC_H
#define PC_H

#include <iostream>
#include <string>

#include "Character.h"
#include "Inventory.h"
#include "Item.h"

/**
 * @class PC PC.h "PC.h"
 * @brief A class for the functionality of the player character
 */
class PC : public Character {
 public:
  /**
   * @brief constructor, calls Character constructor.
   * @param[in] name A name for the PC.
   * @param[in] inv An inventory for the PC.
   */
  PC(std::string name = "Unnamed", Inventory inv = {});

  /**
   * @brief deconstructor.
   */
  ~PC() {}

  /**
   * @brief adds a Item pointer to the Inventory.
   * @param[in] found A pointer to a Item.
   */
  void pickUpItem(Item *found);

  /**
   * @brief Remove one Item pointer from the Inventory.
   * @param[in] name A pointer to a Item.
   */
  Item* putDownItem(std::string name);

  /**
   * @brief gets the interaction options
   * @param[in] n The option chosen
   * @return string of option
   */
  std::string getInteractOptionsInv(int n);

  /**
   * @brief gets the name of the item
   * @param[in] index The number of the item in the inventory
   * @return A string of the item selected
   */
  const std::string getItemNameChar(int index);
};

#endif
