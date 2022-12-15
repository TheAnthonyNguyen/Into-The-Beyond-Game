
#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>

/**
* @class environment_error Exceptions.h "Exceptions.h"
* @brief Exception for a when the PC tries to go to non-exitant environment
*/
class environment_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit environment_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* @class character_error Exceptions.h "Exceptions.h"
* @brief Exception for character
*/
class character_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit character_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* @class inventory_error Exceptions.h "Exceptions.h"
* @brief Exception for accessing non-existant item or making illegal connection
*/
class inventory_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit inventory_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

#endif //EXCEPTIONS_H_INCLUDED
