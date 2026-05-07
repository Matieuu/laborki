#include "Inventory.hpp"
#include "Item.hpp"
#include <cstddef>

std::ostream &operator<<(std::ostream &os, const Inventory &obj) {
  for (auto it = obj.base.begin(); it != obj.base.end(); ++it) {
    std::cout << *it << "\n";
  }
  return os;
}

Inventory &Inventory::operator+=(Item obj) {
  base.push_back(obj);
  return *this;
}

Item &Inventory::operator[](std::size_t k) { return base.at(k); }
