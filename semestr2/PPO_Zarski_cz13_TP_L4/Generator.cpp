#include "Point.cpp"
#include <cstdlib>

template <class T> void generate_points(Point<T> *point) {
  point->set_x((double)(std::rand() % 50000) / 1000.0);
  point->set_y((double)(std::rand() % 50000) / 1000.0);
}

template <class T> void generate_points(Point<T> *point, T start, T end) {
  point->set_x((double)(std::rand() % (int)((double)end * 1000.0)) / 1000.0 +
               (double)start);
  point->set_y((double)(std::rand() % (int)((double)end * 1000.0)) / 1000.0 +
               (double)start);
}
