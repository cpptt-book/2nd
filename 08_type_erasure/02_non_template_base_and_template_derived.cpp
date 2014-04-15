// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

class base {
public:
  virtual ~base() {}
  virtual void foo() = 0;
};

template <class T>
class derived : public base {
  T value_;
public:
  derived(const T& value) : value_(value) {}
  virtual ~derived() {}

  virtual void foo()
  {
    value_.foo();
  }
};

class X {
  base* p_;
public:
  template <class T>
  X(const T& value)
  {
    p_ = new derived<T>(value);
  }

  ~X()
  {
    delete p_;
  }

  void foo()
  {
    p_->foo();
  }
};

#include <iostream>
struct Y {
  void foo()
  {
    std::cout << "foo" << std::endl;
  }
};

int main()
{
  Y y;
  X x(y);

  x.foo();
}
