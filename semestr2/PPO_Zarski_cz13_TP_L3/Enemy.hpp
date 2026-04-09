#pragma once

class Enemy {
protected:
  float x_;
  float y_;
  float strength_;
  Enemy();
  Enemy(float x, float y, float s);

public:
  ~Enemy();
  void update_position(float x, float y);

  virtual void show() = 0;
  virtual void attack(float factor) = 0;
  virtual void make_sound() = 0;

  float get_x() const;
  float get_y() const;
  float get_strength() const;

  void set_x(float x);
  void set_y(float y);
  void set_strength(float strength);
};