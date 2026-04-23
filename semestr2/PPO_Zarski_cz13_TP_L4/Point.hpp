#pragma once

template <class T> class Point {
private:
  T x_;
  T y_;

public:
  Point(T x, T y);
  ~Point();

  T get_x() const;
  T get_y() const;
  void set_x(T x);
  void set_y(T y);

  void show();
};
