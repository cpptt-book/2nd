// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>

template <class Derived>
struct base {
  void base_foo() const
  {
    static_cast<const Derived&>(*this).foo();
  }
};

struct derived : public base<derived> {
  void foo() const
  {
    std::cout << "foo" << std::endl;
  }
};

int main()
{
  derived d;
  d.base_foo(); // foo
}
