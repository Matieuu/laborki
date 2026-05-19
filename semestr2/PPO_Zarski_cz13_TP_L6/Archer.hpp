#pragma once
#include "Character.hpp"
#include <format>
#include <iostream>

class Archer : public Character {
private:
  double power_;

public:
  Archer() : Character(), power_(10.0) {}
  Archer(std::string name, double health, double power)
      : Character(name, health), power_(power) {}

  void showInfo() override {
    std::cout << std::format("Archer {}\n\thealth: {}\n\tpower: {}", name_,
                             health_, power_);
  }
};
