/**
 * @author Cameron Rose <c.rose@uleth.ca>
 * @date Fall 2022
 */

#ifndef IntoTheBeyond_H
#define IntoTheBeyond_H

#include "Inventory.h"
#include "Character.h"
#include "PC.h"
#include "Environment.h"
#include "Exceptions.h"
#include <vector>
#include <string>

/**
 * @class IntoTheBeyond IntoTheBeyond.h "IntoTheBeyond.h"
 * @brief This will act as the main game engine, it will build and run the game.
 */
class IntoTheBeyond {
 public:
  /**
   * @brief This will handle the construction of the game.
   * @details This will make the basic layout and the initial inventories and character locations.
   */
  IntoTheBeyond();

  /**
   * @brief Deletes all necessary pointers.
   */
  ~IntoTheBeyond();

  /**
   * @brief Actually runs the game.
   * @details Very smelly, violates many SOLID and DRY principles.
   */
  void startGame();

  /**
   * @brief Changes the Environments attribute.
   * @details This will check if the vector is empty then add them.
   * @param[in] environment The vector of environments we will change to.
   */
  void setEnvironments(std::vector<Environment*> environment);

  /**
   * @brief Returns the inventory from the room.
   * @details This will give us access to the inventory from a room.
   * @param[in] environment This is the environment we are searching.
   * @return Returns the inventory.
   */
  Inventory searchRoom(Environment *environment);

  /**
   * @brief Returns the current vector of environments.
   * @return Returns a vector.
   */
  std::vector<Environment*> getEnvironments();

  /**
   * @brief Removes an item from the environment and adds it to the character's inventory.
   * @param[in] n This is the index at which the item is located at in a vector.
   * @param[in] you The PC that will be picking up the item.
   * @throw inventory_error Throws incase the item is not in the environment.
   */
  void pickUpItem(int n, PC *you);

  /**
   * @brief Removes an item from the character and adds to Environment's inventory.
   * @param[in] n This is the index at which the item is located at in a vector.
   * @param[in] you The PC that will be putting down the item.
   * @throw inventory_error Throws incase the item is not in the character.
   */
  void putDownItem(int n, PC *you);

  /**
   * @brief Displays the basic UI calls.
   */
  void displayUI();

  void displayChars(PC* you);

  /**
   * @brief Displays all of the keybinds and their descriptions.
   */
  void displayHelp();

  /**
   * @brief Displays the description of an environment and lists its inventory.
   * @param[in] you Displays the environment that you is located in.
   */
  void displaySurroundings(PC* you);

  /**
   * @brief Takes in the users input to chose a specific item.
   * @details Calls the function getInput.
   * @returns An int corresponding to the index of the chosen object.
   */
  int displaySurroundingsUI();

  /**
   * @brief Used to get the current room a PC is located in.
   * @param[in] you The PC you want the location of.
   * @return A Environment pointer from the data member environments.
   */
  Environment* currentRoom(PC *you);

  /**
   * @brief Displays the name of the room you is in.
   * @param[in] you A PC pointer.
   */
  void displayCurrentRoom(PC* you);

  /**
   * @brief Get interaction options for objects in environments.
   * @details Calls the function getInteractionOptions in Environment.
   * @param[in] n This is the index at which the item is located at in a vector.
   * @param[in] you The PC that will be picking up the item.
   * @return A string that describes the chosen interaction.
   */
  std::string getInteractOptions(int n, PC *you);

  /**
   * @brief Get interaction options for objects in PC inventory.
   * @details Calls the function getInteractionOptions in a Character.
   * @param[in] n This is the index at which the item is located at in a vector.
   * @param[in] you The PC that will be putting down the item.
   * @return A string that describes the chosen interaction.
   */
  std::string getInteractOptionsInv(int n, PC *you);

  /**
   * @brief Perform the desired interaction with environment chosen from user.
   * @details calls the function pickUpItem.
   * @param[in] n This is the index at which the item is located at in a vector.
   * @param[in] you The PC that will be picking up the item.
   * @param[in] choice The string for which interaction is executed.
   */
  void executeInteraction(int n, PC *you, std::string choice);

  /**
   * @brief Perform the desired interaction with PC inventory chosen from user.
   * @details calls the function putDownItem.
   * @param[in] n This is the index at which the item is located at in a vector.
   * @param[in] you The PC that will be putting down the item.
   * @param[in] choice The string for which interaction is executed.
   */
  void executeInteractionInv(int, PC*, std::string);

  /**
   * @brief Gets name of an item in a Environment at index.
   * @details Calls getItemName in Environemnt.
   * @param[in] index The index for a item in a vector.
   * @param[in] you A PC pointer.
   * @return A string of an item objects name.
   */
  const std::string getItemName(int index, PC *you);

  /**
   * @brief Gets name of an item in a character inventory at index.
   * @details Calls getItemNameChar in Character.
   * @param[in] index The index for a item in a vector.
   * @param[in] you A PC pointer.
   * @return A string of an item objects name.
   */
  const std::string getItemNameChar(int index, PC *you);

  /**
   * @brief Moves a PC up,down,left,right between environments.
   * @details Calls current room and functions from environment.
   * @param[in] index The index for a item in a vector.
   * @param[in] you A PC pointer.
   */
  void movePlayer(int index, PC *you);

  /**
   * @brief Takes in and verifies user input.
   * @details Converts string input to an int.
   * @return An int representing a valid input.
   */
  int getInput();

 private:
  std::vector<Environment*> Environments;
};

#endif //IntoTheBeyond_H
