/**
 * @author Sarah Alibhai <sarah.alibhai@uleth.ca>
 * @date 2022-11-16
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include "Inventory.h"

/**
 * @class Character Character.h "Character.h"
 * @brief A class for the functionality of all characters
 */
class Character {
 public:
  /**
   * @brief constructor.
   * @param[in] name Name of the Character.
   * @param[in] bag Inventory of the Character.
   */
  Character(std::string name = "Unnamed", Inventory bag = { });

  /**
   * @brief deconstructor.
   */
  ~Character() {}

  /**
   * @brief Access the name of Character.
   * @return The name of Character.
   */
  std::string getName();

  /**
   * @brief Modify the name of Character.
   * @param[in] n A name for the Character.
   */
  void setName(std::string n);

  /**
   * @brief access inventory of Character
   * @return inventory of Character
   */
  Inventory getInventory();

  /**
   * @brief shows what is in the inventory
   * @return items inside the inventory
   */
  const void displayInventory() const;

 protected:
  /**
   * @brief the Inventory that the character has
   */
  Inventory inventory;

 private:
  std::string name;
};

#endif
