#include "Item.hpp"
#include <format>
#include <iostream>

std::ostream &operator<<(std::ostream &os, const Item &obj) {
  os << std::format("Item (defence: {}, attack: {}, critical hit chance: {})",
                    obj.defence_, obj.attack_, obj.critChance_);
  return os;
}

std::istream &operator>>(std::istream &is, Item &obj) {
  std::cout << "Defence: ";
  is >> obj.defence_;

  std::cout << "Attack: ";
  is >> obj.attack_;

  std::cout << "Critical hit chance: ";
  is >> obj.critChance_;

  return is;
}

Item operator+(const Item &lhs, const Item &rhs) {
  return Item(lhs.getDefence() + rhs.getDefence(),
              lhs.getAttack() + rhs.getAttack(),
              lhs.getCritChance() + rhs.getCritChance());
}
