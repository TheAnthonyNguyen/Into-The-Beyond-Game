/**
 * @author Sarah Alibhai <sarah.alibhai@uleth.ca>
 * @date 2022-12-04
 */

#ifndef LOCK_H
#define LOCK_H

#include <iostream>
#include <string>

#include "Item.h"

/**
 * @class Key Lock.h "Lock.h"
 * @brief A class for the functionality of all keys.
 */
class Key : public Item {
 public:
  /**
   * @brief default constructor.
   * @details Sets defaults for Key.
   */
  Key();

  /**
   * @brief default constructor, calls Item constructor
   * @param[in] name The name of the key
   * @param[in] description Key description.
   * @param[in] ID Unique key ID used for pairing with lock.
   */
  Key(std::string name, std::string description = "Shapeless Floating", int ID =
          0)
      :
      Item(name),
      description(description),
      ID(ID) {
  }

  /**
   * @brief copy constructor.
   * @param[in] copy The Key you're copying from a vector.
   */
  Key(const Key &copy);

  /**
   * @brief returns description.
   * @return returns a stirng with the description and the ID.
   */
  Key* Clone() {
    return new Key(*this);
  }

  /**
   * @brief sets the ID for the Key
   * @param[in] num The number for the ID
   */
  void setID(int num);

  /**
   * @brief returns ID
   * @return returns an int with the ID
   */
  int getID();

  /**
   * @brief sets the desciption of the Key
   * @param[in] adjective A string that describes the Key
   */
  void setDescription(std::string adjective);

  /**
   * @brief return the description
   * @return a string of the description
   */
  std::string getDescription();

 private:
  /**
   * @brief the description of the Key
   */
  std::string description;
  /**
   * @brief the ID of the key
   */
  int ID;
};

/**
 * @class Lock Lock.h "Lock.h"
 * @brief A class for the functionality of all locks
 */
class Lock : public Item {
 public:
  /**
   * @brief default constructor.
   * @details Sets defaults for Lock.
   */
  Lock();

  /**
   * @brief default constructor, calls Item constructor.
   * @param[in] name The name of the Lock
   * @param[in] use What the Lock is made for.
   * @param[in] ID Unique key ID used for pairing with lock.
   */
  Lock(std::string name, std::string use = "Currently Useless", int ID = 0)
      :
      Item(name),
      use(use),
      ID(ID) {
  }

  /**
   * @brief copy constructor.
   * @param[in] copy The Key you're copying from a vector.
   */
  Lock(const Lock &copy);

  /**
   * @brief returns description.
   * @return returns a stirng with the description and the ID.
   */
  Lock* Clone() {
    return new Lock(*this);
  }

  /**
   * @brief sets the ID for the Lock
   * @param[in] num The number for the ID
   */
  void setID(int);

  /**
   * @brief returns ID
   * @return returns an int with the ID
   */
  int getID();

  /**
   * @brief sets the desciption of the Key
   * @param[in] purpose A string that describes the purpose of Lock
   */
  void setUse(std::string purpose);

  /**
   * @brief return the use of the Lock.
   * @return a string of the use
   */
  std::string getUse();

  /**
   * @brief compares the ID if the key to the Lock.
   * @param[in] thisKey The key being used on the Lock
   * @return true if the ID of the key and the lock are the same
   */
  bool pair(Key *thisKey);

 private:
  std::string use;
  int ID;
};

#endif

