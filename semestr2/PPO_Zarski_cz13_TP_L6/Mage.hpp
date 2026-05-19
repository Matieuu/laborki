#pragma once
#include "Character.hpp"
#include <format>
#include <iostream>

class Mage : public Character {
private:
  double mana_;

public:
  Mage() : Character(), mana_(10.0) {}
  Mage(std::string name, double health, double mana)
      : Character(name, health), mana_(mana) {}

  void showInfo() override {
    std::cout << std::format("Mage {}\n\thealth: {}\n\tmana: {}", name_,
                             health_, mana_);
  }
};
