// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <cmath>

class point {
  double x_ = 0;
  double y_ = 0;
public:
  point() = default;
  point(double x, double y)
    : x_(x), y_(y) {}

  // それぞれの座標を取得する
  double x() const { return x_; }
  double y() const { return y_; }
};

// pointの減算
point operator-(const point& a, const point& b)
  { return point(a.x() - b.x(), a.y() - b.y()); }

template <class Point>
double distance(Point a, Point b)
{
  const Point d = a - b;
  return std::sqrt(d.x() * d.x() + d.y() * d.y());
}

int main()
{
  point a(0.0, 0.0);
  point b(3.0, 3.0);

  double d = distance(a, b);
  std::cout << d << std::endl;
}
