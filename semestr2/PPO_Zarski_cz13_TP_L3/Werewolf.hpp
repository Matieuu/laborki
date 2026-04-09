#pragma once
#include "Enemy.hpp"

class Werewolf : public Enemy {
private:
  float radius_;

public:
  Werewolf();
  Werewolf(float x, float y, float s, float r);
  ~Werewolf();

  void show() override;
  void make_sound() override;
  void attack(float factor) override;

  float get_radius() const;
  void set_radius(float radius);
};