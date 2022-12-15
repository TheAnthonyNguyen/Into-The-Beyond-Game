/**
 * @author Ethan Kostiuk <ethan.kostiuk@uleth.ca>
 * @date 2022-11-15
 */

#ifndef Inventory_H
#define Inventory_H

#include <iostream>
#include <vector>
#include <string>

#include "Item.h"

/**
 * @class Inventory Inventory.h "Inventory.h"
 * @brief A class for storing different types of items
 */
class Inventory {
 public:
  /**
   * @brief default constructor.
   */
  Inventory();

  Inventory(std::initializer_list<Item*> i);

  ~Inventory();

  Inventory& operator=(const Inventory &inv);

  /**
   * @brief adds a Item pointer to the end of Items vector.
   * @param[in] I A pointer to a Item.
   */
  void addItem(Item *I);

  /**
   * @brief Displays each element in Items in a list.
   * @details If Items if empty it will output a string Inventory is Empty.
   */
  const void showInventory() const;

  /**
   * @brief Find an Item with the given name.
   * @param[in] name A name of an Item object.
   * @returns A item pointer if item is found, else NULL.
   */
  Item* findItem(std::string name);

  /**
   * @brief Remove one Item pointer from the vector Items.
   * @details Vector shrinks to fit after removal.
   * @param[in] s Type string.
   * @return Item pointer.
   */
  Item* removeItem(std::string s);

  /**
   * @brief Checks if Items if empty.
   * @returns true if empty or false if not empty.
   */
  bool isEmpty();

  const bool operator==(const Inventory &inv) const;

  std::vector<Item*> getItems();

  std::string getInteractOptions(int n);

  std::string getInteractOptionsInv(int n);

  const std::string getItemName(int index);

  const std::string getItemNameChar(int index);

 private:
  std::vector<Item*> Items;
};

#endif
