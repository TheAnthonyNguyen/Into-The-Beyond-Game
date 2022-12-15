#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include <string>

#include "Environment.h"
#include "Exceptions.h"
#include "Item.h"
#include "Lock.h"
#include "Inventory.h"

/**
 * @class Room Room.h "Room.h"
 * @brief A class that contains the rooms.
 */
class Room : public Environment {
 public:
  /**
   * @brief A default constructor.
   * @param[in] name string name
   * @param[in] inv Inventory items
   * @param[in] characters The characters in the room
   * @param[in] desc A description of a room.
   * @param[in] lock An object that represents a lock.
   */
  Room(std::string name = "Empty", Inventory inv = { },
       std::vector<Character*> characters = { },
       std::string desc = "Basic Room", Lock *lock = nullptr);

  ~Room() {
    delete lock;
  }

  /**
   * @brief sets Lock to room.
   * @param[in] locks The lock being added to room
   */
  void setLock(Lock *locks);

  /**
   * @brief compares lock and key.
   * @details returns true if the key is able to unlock the lock.
   * @param[in] keys The keys being used
   * @return bool which returns true if key matches lock
   */
  bool getLocked(Key *keys);

  /**
   * @brief returns state of lock in room.
   * @return returns true if room is locked
   */
  bool lockStatus();

  /**
   * @brief Locks the room.
   */
  void LockRoom();

  /**
   * @brief sets description for room.
   * @param[in] d the description
   */
  void setDesc(std::string d);

  /**
   * @brief returns description of room.
   * @return returns description of room
   */
  std::string getDesc();

  Lock* getLock();

 private:
  bool locked = true;
  Lock *lock;
};

#endif
