// #include "Character.hpp"
// #include "CharacterFactory.hpp"
#include "Character.hpp"
#include "CharacterFactories.hpp"
#include <iostream>
#include <string>

int main(void) {
  std::string type;

  std::cout << "Insert character type: ";
  std::cin >> type;

  CharacterFactory *factory = nullptr;
  if (type == "mage") {
    factory = new MageFactory();
  } else if (type == "archer") {
    factory = new ArcherFactory();
  } else if (type == "warrior") {
    factory = new WarriorFactory();
  } else {
    std::cout << "Invalid Character type\n";
    return 0;
  }

  //   Character *c = factory.createCharacter(type);
  Character *c = factory->generate();
  c->showInfo();

  //   if (c == nullptr) {
  //       std::cout << "Invalid Character type\n";
  //   } else {
  //       c->showInfo();
  //   }

  delete c;
  return 0;
}
