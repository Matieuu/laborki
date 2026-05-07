#pragma once

#include "Item.hpp"
#include <cstddef>
#include <ostream>
#include <vector>
class Inventory {
private:
  std::vector<Item> base;

public:
  friend std::ostream &operator<<(std::ostream &os, const Inventory &obj);
  Inventory &operator+=(Item obj);
  Item &operator[](std::size_t k);
};
