#pragma once

#include <string>
class Character {
protected:
  std::string name_;
  double health_;

public:
  Character() : name_("Postać"), health_(20.0) {}
  Character(std::string name, double health) : name_(name), health_(health) {}
  virtual ~Character() {}
  virtual void showInfo() = 0;
};
