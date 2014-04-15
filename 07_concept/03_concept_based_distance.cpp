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

template <class T>
struct point_traits {
  static double x(const T& p) { return p.x(); }
  static double y(const T& p) { return p.y(); }

  static T subtract(const T& a, const T& b)
    { return T(a.x() - b.x(), a.y() - b.y()); }
};

template <class Point>
double distance(Point a, Point b)
{
  typedef point_traits<Point> traits;
  const Point d = traits::subtract(a, b);
  return std::sqrt(traits::x(d) * traits::x(d) +
                   traits::y(d) * traits::y(d));
}

int main()
{
  point a(0.0, 0.0);
  point b(3.0, 3.0);

  double d = distance(a, b);
  std::cout << d << std::endl;
}
