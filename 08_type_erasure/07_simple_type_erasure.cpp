// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <boost/function.hpp>

using std::cout;
using std::endl;
using boost::function;

class drawable {
  function<void()> draw_func_;
public:
  drawable() {}

  template <class T>
  drawable(T& obj)
    : draw_func_([&obj] { obj.draw(); }) {}

  template <class T>
  drawable& operator=(T& obj)
  {
    draw_func_ = [&obj] { obj.draw(); };
    return *this;
  }

  void draw() const
  {
    draw_func_();
  }
};

struct circle {
  void draw() const
  {
    cout << "円を描画する" << endl;
  }
};

struct square {
  void draw() const
  {
    cout << "四角形を描画する" << endl;
  }
};

int main()
{
  drawable a;

  circle c;
  a = c;
  a.draw();

  square s;
  a = s;
  a.draw();
}
