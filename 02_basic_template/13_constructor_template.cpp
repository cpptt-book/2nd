// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>

template <class T>
class Point {
  template<class> friend class Point;
private:
  T x_;
  T y_;
public:
  // これがコンストラクタテンプレート
  template <class U>
  Point(const Point<U>& r) : x_(r.x_), y_(r.y_) {}

  Point(T x = T(), T y = T()) : x_(x), y_(y) {}
  Point(const Point& pt) : x_(pt.x_), y_(pt.y_) {}
  void print(std::ostream& s) const
    { return s << '(' << x_ << ',' << y_ << ')'; }
};


int main()
{
  Point<int>  ip(12, 34);
  Point<long> lp(ip);
}
