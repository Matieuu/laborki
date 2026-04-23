#include "Comparison.hpp"
#include "Point.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numbers>

template <typename T>
Comparison<T>::Comparison(Point<T> p1, Point<T> p2)
    : p1_(p1), p2_(p2), solution_(std::abs(p2.get_x() - p1.get_x()),
                                  std::abs(p2.get_y() - p1.get_y())) {}

template <typename T> Comparison<T>::~Comparison() {
  std::cout << "Destruktor klasy Comparison\n";
}

template <typename T> Point<T> Comparison<T>::get_p1() const { return p1_; }
template <typename T> Point<T> Comparison<T>::get_p2() const { return p2_; }
template <typename T> Point<T> Comparison<T>::get_solution() const {
  return solution_;
}

template <typename T> Point<T> Comparison<T>::get_center() {
  calc();
  Point center(std::max(solution_.get_x(), solution_.get_y()) / 2,
               std::max(solution_.get_x(), solution_.get_y()) / 2);

  center.set_x(std::max(p1_.get_x(), p2_.get_x()) - center.get_x());
  center.set_y(std::max(p1_.get_y(), p2_.get_y()) - center.get_y());

  return center;
}

template <typename T> T Comparison<T>::get_radius() {
  calc();
  return 2.0 * std::numbers::pi *
         (std::max(solution_.get_x(), solution_.get_y()) / 2.0);
}

template <typename T> void Comparison<T>::set_p1(Point<T> p) {
  p1_ = p;
  calc();
}
template <typename T> void Comparison<T>::set_p2(Point<T> p) {
  p2_ = p;
  calc();
}

template <typename T> void Comparison<T>::locate() {
  std::cout << "1. ";
  p1_.show();
  std::cout << "2. ";
  p2_.show();
}

template <typename T> void Comparison<T>::show_all() {
  locate();
  std::cout << "Solution: ";
  solution_.show();

  std::cout << "Środek: ";
  get_center().show();

  std::cout << "Obwód: " << get_radius() << std::endl;
}

template <typename T> void Comparison<T>::calc() {
  solution_ = Point(std::abs(p2_.get_x() - p1_.get_x()),
                    std::abs(p2_.get_y() - p1_.get_y()));
}
