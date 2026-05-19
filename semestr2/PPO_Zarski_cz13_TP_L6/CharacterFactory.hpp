#pragma once

// #include "Archer.hpp"
// #include "Mage.hpp"
// #include "Warrior.hpp"
// #include <algorithm>
// #include <string>
#include "Character.hpp"

class CharacterFactory {
public:
  virtual Character *generate() = 0;
  ~CharacterFactory() {}

  // Character *createCharacter(std::string type) {
  //   std::transform(type.begin(), type.end(), type.begin(),
  //                  [](unsigned char c) { return std::tolower(c); });

  //   if (type == "mage") {
  //     return new Mage();
  //   } else if (type == "archer") {
  //     return new Archer();
  //   } else if (type == "warrior") {
  //     return new Warrior();
  //   } else {
  //     // throw std::invalid_argument("Invalid Character type");
  //     return nullptr;
  //   }
  // }
};
