// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>

class Foo {
  int value_;
public:
  Foo(int v) : value_(v) {}

  template <class T>
  void get(T& dst) const
  {
    dst = value_;
  }

//……
};


int main()
{
  Foo f(3);
  long v;
  f.get(v);

  std::cout << v << std::endl;
}
