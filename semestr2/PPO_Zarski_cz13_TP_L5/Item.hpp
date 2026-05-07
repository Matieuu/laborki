#pragma once
#include <iostream>

class Item {
protected:
  double defence_;
  double attack_;
  double critChance_;

public:
  Item() : defence_(0.0), attack_(0.0), critChance_(0.0) {}
  Item(double defence, double attack, double critChance)
      : defence_(defence), attack_(attack), critChance_(critChance) {}

  friend std::ostream &operator<<(std::ostream &os, const Item &obj);
  friend std::istream &operator>>(std::istream &is, Item &obj);
  friend Item operator+(const Item &lhs, const Item &rhs);

  double getDefence() const { return defence_; }
  double getAttack() const { return attack_; }
  double getCritChance() const { return critChance_; }
};
