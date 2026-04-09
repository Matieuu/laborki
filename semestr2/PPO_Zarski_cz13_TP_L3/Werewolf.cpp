#include "Werewolf.hpp"

#include <format>
#include <iostream>

Werewolf::Werewolf() : Enemy(), radius_(0.0) {}
Werewolf::Werewolf(float x, float y, float s, float r)
    : Enemy(x, y, s), radius_(r) {}
Werewolf::~Werewolf() { std::cout << "Werewolf destroyed\n"; }

void Werewolf::show() {
  std::cout << std::format(
                   "The Werewolf is at point ({}, {}) and its radius is {}", x_,
                   y_, radius_)
            << std::endl;
}

void Werewolf::make_sound() { std::cout << "Werewolf's growl\n"; }

void Werewolf::attack(float factor) {
  strength_ -= strength_ * factor;
  radius_ *= 1.5;
  make_sound();
}

float Werewolf::get_radius() const { return radius_; }
void Werewolf::set_radius(float radius) { radius_ = radius; }
