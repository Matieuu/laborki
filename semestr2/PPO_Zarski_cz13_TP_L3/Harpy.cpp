#include "Harpy.hpp"

#include <format>
#include <iostream>

Harpy::Harpy() : Enemy(), height_(0.0) {}
Harpy::Harpy(float x, float y, float s, float h) : Enemy(x, y, s), height_(h) {}
Harpy::~Harpy() { std::cout << "Harpy destroyed\n"; }

void Harpy::show() {
  std::cout << std::format(
                   "The Harpy is at point ({}, {}) and its height is {}", x_,
                   y_, height_)
            << std::endl;
}

void Harpy::make_sound() { std::cout << "Harpy's yell\n"; }

void Harpy::attack(float factor) {
  strength_ -= strength_ * factor;
  height_ = 1.85;
  make_sound();
}

float Harpy::get_height() const { return height_; }
void Harpy::set_height(float height) { height_ = height; }
