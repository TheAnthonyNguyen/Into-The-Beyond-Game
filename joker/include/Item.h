/**
 * @author Ethan Kostiuk <ethan.kostiuk@uleth.ca>
 * @date 2022-11-15
 */

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

/**
 * @class Item Item.h "Item.h"
 * @brief A base class for all Items.
 */
class Item {
 public:
  /**
   * @brief default constructor.
   * @param[in] name A name for the item.
   */
  Item(std::string name = "UnNamed");

  /**
   * @brief copy constructor.
   * @param[in] copy The Item you're copying.
   */
  Item(const Item& copy);

  /**
   * @brief Returns a pointer to the type of the Item.
   * @details Used for the copy constructor when 
   *      adding to a vector,  ensures type is saved.
   */
  virtual Item* Clone() = 0;

  /**
   * @brief default virtual destructor.
   */
  virtual ~Item() {}

  /**
   * @brief Selects the options.
   * @param[in] c int value of the chosen option.
   * @return returns a string saying there are no options
   */
  virtual std::string interactOptions(int c);

  /**
   * @brief Selects the options.
   * @param[in] c int value of the chosen option.
   * @return returns a string saying there are no options
   */
  virtual std::string getInteractOptionsInv(int c);

  /**
   * @brief Modify the name of Item.
   * @param[in] name A name for the Item.
   */
  void setName(std::string name);

  /**
   * @brief Access the name of Item.
   * @return The name of Item.
   */
  const std::string getName() const;

  /**
   * @brief equality operator.
   * @param[in] item The item you are comparing to.
   */
  bool operator==(const Item &item);

 private:
  /**
   * @brief name of the item
   */
  std::string name;
};

/**
 * @class Duck Item.h "Item.h"
 * @brief A concrete class of Item representing a Duck.
 */
class Duck : public Item {
 public:
  /**
   * @brief default constructor.
   * @details Sets description of Duck to a default string.
   */
  Duck();


  /**
   * @brief Returns a new Duck copy pointer.
   * @details Used for the copy constructor when 
   *      adding to a vector,  ensures type is saved.
   */
  Duck* Clone() {
    return new Duck(*this);
  }

  /**
   * @brief default constructor, calls Item constructor.
   * @param[in] name The name of the duck
   * @param[in] description A description for the Duck
   */
  Duck(std::string name, std::string description = "Boring duck")
      :
      Item(name),
      description(description) {
  }

  /**
   * @brief copy constructor.
   * @param[in] copy The Duck you're copying from a vector, helps fix a bug.
   */
  Duck(const Duck& copy);

  /**
   * @brief returns description.
   * @return returns a stirng with the description.
   */
  std::string getDescription();

  /**
   * @brief Selects the options.
   * @param[in] c int value of the chosen option, should be removed.
   * @return returns a string with the choice.
   */
  std::string interactOptions(int c);

  /**
   * @brief Selects the options.
   * @details prints the options to the screen, then overwrites the input, then returns a string with the choice.
   * @param[in] c int value of the chosen option, should be removed.
   * @return returns a string with the choice, part of interface.
   */
  std::string getInteractOptionsInv(int c);

 private:
   /**
   * @brief Describes the duck in a string.
   */
  std::string description;
};

#endif
