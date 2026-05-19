#pragma once
#include "Character.hpp"
#include <format>
#include <iostream>

class Warrior : public Character {
private:
  double strength_;

public:
  Warrior() : Character(), strength_(10.0) {}
  Warrior(std::string name, double health, double strength)
      : Character(name, health), strength_(strength) {}

  void showInfo() override {
    std::cout << std::format("Warrior {}\n\thealth: {}\n\tstrength: {}", name_,
                             health_, strength_);
  }
};
