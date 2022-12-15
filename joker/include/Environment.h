/**
 * @author Anthony Nguyen <anthony.nguyen2@uleth.ca>
 * @date Fall 2022
 */

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include "Inventory.h"
#include "Exceptions.h"
#include "Character.h"
#include <vector>
#include <string>

/**
 * @class Environment Environment.h "Environment.h"
 * @brief A class that contains everything in the game.
 */
class Environment {
 public:
  /**
   * @brief default constructor.
   */
  Environment(std::string name = "Empty", Inventory inv = { },
              std::vector<Character*> characters = { }, std::string desc =
                  "Basic Environment");

  /**
   * @brief destructor.
   */
  virtual ~Environment();

  /**
   * @brief returns the Environment's name
   * @return name A string for the name
   */
  std::string getName();

  /**
   * @brief returns the connections
   */
  //std::vector<Environment*> getConnections();
  /**
   * @brief returns the characters
   */
  std::vector<Character*> getCharacters();

  /**
   * @brief returns the characters inventory
   */
  Inventory getInventory();

  /**
   * @brief returns Player.
   */
  bool getPC();

  /**
   * @brief Adds character to the environment.
   * @param[in] ch A pointer to character.
   */
  void addCharacter(Character *ch);

  /**
   * @brief Removes character from the environment.
   * @param[in] ch A pointer to character.
   */
  void removeCharacter(Character *ch);

  /**
   * @brief Adds item to environment
   * @param[in] it A pointer to Item.
   */
  void addItem(Item *it);

  /**
   * @brief Removes item from the environment.
   * @param[in] name The name of the item as a string.
   */
  Item* removeItem(std::string name);

  //void addConnection(Environment *en);

  //void removeConnection(Environment *en);

  /**
   * @brief Toggles the character in the environment.
   */
  void togglePC();

  std::string getUP();
  std::string getLEFT();
  std::string getDOWN();
  std::string getRIGHT();

  /**
   * @brief Sets the movement to go up.
   */
  void setUP(std::string);

  /**
   * @brief Sets the movement to go left.
   */
  void setLEFT(std::string);

  /**
   * @brief Sets the movement to go down.
   */
  void setDOWN(std::string);

  /**
   * @brief Sets the movement to go right.
   */
  void setRIGHT(std::string);

  /**
   * @brief Displays the inventory of character.
   */
  void displayInventory();

  /**
   * @brief Displays the characters in the environment.
   */
  void displayCharacters();

  /**
   * @brief Returns the interact options for the inventory.
   * @param[in] i The number that get passed in corresponds with the option 
   * choice displayed.
   * @return Interact options from inventory.
   */
  std::string getInteractOptions(int i);

  /**
   * @brief Returns the item name thats in inventory.
   * @param[in] index Chooses what item specifcally to choose in the inventory.
   * @return Item name at index.
   */
  const std::string getItemName(int index);

  const std::string getDesc();

  void setDesc(std::string d);

 protected:
  std::string name, desc;
  Inventory inventory;
  std::string UP, LEFT, DOWN, RIGHT;
  /**
   * @brief sets the inventory of characters.
   * @param[in] inventory Type inventory.
   */
  void setInventory(Inventory inventory);

  /**
   * @brief sets the Characters inside the environment.
   * @param[in] Characters A vector of type Character pointer.
   */
  void setCharacters(std::vector<Character*> Characters);

 private:
  std::vector<Character*> characters;
  bool pcPresent;

  /**
   * @brief sets the connections between rooms
   * @param[in] A pointer to Connections
   
   void setConnections(std::vector<Environment*> Connections);
   */
};

#endif
