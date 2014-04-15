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

class MyPoint {
  double x_ = 0;
  double y_ = 0;
public:
  MyPoint() = default;
  MyPoint(double x, double y)
    : x_(x), y_(y) {}

  double getX() const { return x_; }
  double getY() const { return y_; }
};

template <>
struct point_traits<MyPoint> {
  static double x(const MyPoint& p) { return p.getX(); }
  static double y(const MyPoint& p) { return p.getY(); }

  static MyPoint subtract(const MyPoint& a, const MyPoint& b)
    { return MyPoint(a.getX() - b.getX(), a.getY() - b.getY()); }
};

int main()
{
  MyPoint a(0.0, 0.0);
  MyPoint b(3.0, 3.0);

  double d = distance(a, b);
  std::cout << d << std::endl;
}
