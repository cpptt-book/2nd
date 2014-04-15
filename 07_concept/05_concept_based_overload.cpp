// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <cmath> // sqrt
#include <algorithm> // min

struct point_category {};
struct line_segment_category {};

template <class T>
struct get_geometry_category;


template <class T>
struct point_traits {
  static double x(const T& p) { return p.x(); }
  static double y(const T& p) { return p.y(); }

  static T subtract(const T& a, const T& b)
    { return T(a.x() - b.x(), a.y() - b.y()); }
};

template <class T>
struct line_segment_traits {
  typedef typename T::point_type point_type;

  static const point_type&
    p1(const T& line) { return line.p1(); }

  static const point_type&
    p2(const T& line) { return line.p2(); }
};

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

template <>
struct get_geometry_category<point> {
  typedef point_category type;
};

template <class Point>
class line_segment {
  Point p1_;
  Point p2_;
public:
  typedef Point point_type;

  line_segment() = default;
  line_segment(const Point& p1, const Point& p2)
    : p1_(p1), p2_(p2) {}

  const Point& p1() const { return p1_; }
  const Point& p2() const { return p2_; }
};

template <class Point>
struct get_geometry_category<line_segment<Point>> {
  typedef line_segment_category type;
};

// 点と点
template <class Point>
double distance_impl(Point a, Point b,
                     point_category, point_category)
{
  typedef point_traits<Point> traits;
  const Point d = traits::subtract(a, b);
  return std::sqrt(traits::x(d) * traits::x(d) +
                   traits::y(d) * traits::y(d));
}

// 点と線分
template <class Point, class LineSegment>
double distance_impl(Point a, LineSegment b,
                     point_category, line_segment_category)
{
  typedef line_segment_traits<LineSegment> traits;
  return std::min(
           distance(a, traits::p1(b)),
           distance(a, traits::p2(b))
         );
}

// 線分と点
template <class LineSegment, class Point>
double distance_impl(LineSegment a, Point b,
                     line_segment_category, point_category)
{
  return distance(b, a);
}

template <class Geometry1, class Geometry2>
double distance(Geometry1 a, Geometry2 b)
{
  return distance_impl(a, b,
           typename get_geometry_category<Geometry1>::type(),
           typename get_geometry_category<Geometry2>::type());
}

int main()
{
  point p1(0.0, 0.0);
  point p2(3.0, 3.0);
  line_segment<point> line(point(2.0, 2.0), point(3.0, 3.0));

  // 点と点
  double d1 = distance(p1, p2);
  std::cout << d1 << std::endl;

  // 点と線分
  double d2 = distance(p1, line);
  std::cout << d2 << std::endl;
}
