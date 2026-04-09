#include "Enemy.hpp"

#include <iostream>

Enemy::Enemy() : x_(0.0), y_(0.0), strength_(0.0) {}
Enemy::Enemy(float x, float y, float s) : x_(x), y_(y), strength_(s) {}
Enemy::~Enemy() { std::cout << "Enemy destroyed!\n"; }

void Enemy::update_position(float x, float y) {
  x_ += x;
  y_ += y;
}

float Enemy::get_x() const { return x_; }
float Enemy::get_y() const { return y_; }
float Enemy::get_strength() const { return strength_; }

void Enemy::set_x(float x) { x_ = x; }
void Enemy::set_y(float y) { y_ = y; }
void Enemy::set_strength(float strength) { strength_ = strength; }
