#pragma once
#include "Point.hpp"

template <class T> class Comparison {
private:
  Point<T> p1_;
  Point<T> p2_;
  Point<T> solution_;

public:
  Comparison(Point<T> p1, Point<T> p2);
  ~Comparison();

  Point<T> get_p1() const;
  Point<T> get_p2() const;
  Point<T> get_solution() const;

  Point<T> get_center();
  T get_radius();

  void set_p1(Point<T> p);
  void set_p2(Point<T> p);

  void locate();
  void show_all();
  void calc();
};
