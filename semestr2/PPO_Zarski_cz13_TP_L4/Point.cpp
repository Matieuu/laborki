#include "Point.hpp"
#include <iostream>

template <typename T> Point<T>::Point(T x, T y) : x_(x), y_(y) {}
template <typename T> Point<T>::~Point() {
  std::cout << "Destruktor klasy Point\n";
}

template <typename T> T Point<T>::get_x() const { return x_; }
template <typename T> T Point<T>::get_y() const { return y_; }
template <typename T> void Point<T>::set_x(T x) { x_ = x; }
template <typename T> void Point<T>::set_y(T y) { y_ = y; }

template <typename T> void Point<T>::show() {
  std::cout << "Punkt (" << x_ << ", " << y_ << ")\n";
}
