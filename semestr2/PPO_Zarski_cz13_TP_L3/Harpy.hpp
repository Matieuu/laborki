#pragma once
#include "Enemy.hpp"

class Harpy : public Enemy {
private:
  float height_;

public:
  Harpy();
  Harpy(float x, float y, float s, float h);
  ~Harpy();

  void show() override;
  void make_sound() override;
  void attack(float factor) override;

  float get_height() const;
  void set_height(float height);
};