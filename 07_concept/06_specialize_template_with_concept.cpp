// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <cmath> // sqrt
#include <algorithm> // min
#include <utility> // pair
#include <boost/utility/enable_if.hpp>

struct point_category {};

template <class T, class Enable = void>
struct get_geometry_category;

template <class T, class Enable = void>
struct point_traits {
  static double x(const T& p) { return p.x(); }
  static double y(const T& p) { return p.y(); }

  static T subtract(const T& a, const T& b)
    { return T(a.x() - b.x(), a.y() - b.y()); }
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

// 別の計算幾何ライブラリ
namespace geo {

template <class T>
struct is_point_category {
  static const bool value = false;
};

template <class T>
struct point_traits {
  static double getX(const T& p) { return p.getX(); }
  static double getY(const T& p) { return p.getY(); }

  static T subtract(const T& a, const T& b)
    { return T(a.getX() - b.getX(), a.getY() - b.getY()); }
};

class point {
  double x_ = 0;
  double y_ = 0;
public:
  point() = default;
  point(double x, double y)
    : x_(x), y_(y) {}

  // それぞれの座標を取得する
  double getX() const { return x_; }
  double getY() const { return y_; }
};

template <>
struct is_point_category<point> {
  static const bool value = true;
};

template <>
struct point_traits<std::pair<double, double>> {
  typedef std::pair<double, double> point_type;

  static double getX(const point_type& p)
    { return p.first; }

  static double getY(const point_type& p)
    { return p.second; }

  static point_type subtract(
                      const point_type& a,
                      const point_type& b)
  {
    return std::make_pair(
             a.first - b.first,
             a.second - b.second);
  }
};

template <>
struct is_point_category<std::pair<double, double>> {
  static const bool value = true;
};

} // namespace geo

template <class T>
struct get_geometry_category<
         T,
         typename boost::enable_if<
           geo::is_point_category<T>
         >::type
       > {
  typedef point_category type;
};

template <class T>
struct point_traits<
         T,
         typename boost::enable_if<
           geo::is_point_category<T>
         >::type
       > {
  static double x(const T& p) { return geo::point_traits<T>::getX(p); }
  static double y(const T& p) { return geo::point_traits<T>::getY(p); }

  static T subtract(const T& a, const T& b)
    { return geo::point_traits<T>::subtract(a, b); }
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

template <class Geometry1, class Geometry2>
double distance(Geometry1 a, Geometry2 b)
{
  return distance_impl(a, b,
           typename get_geometry_category<Geometry1>::type(),
           typename get_geometry_category<Geometry2>::type());
}

int main()
{
  {
    point p1(0.0, 0.0);
    point p2(3.0, 3.0);

    double d = distance(p1, p2);
    std::cout << d << std::endl;
  }
  {
    geo::point p1(0.0, 0.0);
    geo::point p2(3.0, 3.0);

    double d = distance(p1, p2);
    std::cout << d << std::endl;
  }
  {
    std::pair<double, double> p1(0.0, 0.0);
    std::pair<double, double> p2(3.0, 3.0);

    double d = distance(p1, p2);
    std::cout << d << std::endl;
  }
}
