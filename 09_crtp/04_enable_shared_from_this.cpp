// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

template <class T>
class my_enable_shared_from_this {
  boost::weak_ptr<T> weak_this_;
public:
  boost::shared_ptr<T> shared_from_this()
  {
    boost::shared_ptr<T> p(weak_this_);
    return p;
  }

  void setup_shared_from_this(const boost::shared_ptr<T>& p)
  {
    if (weak_this_.expired()) {
      weak_this_ = p;
    }
  }
};

template <class T>
void print_share(boost::shared_ptr<T> p)
{
  p->print();
}

class X : public my_enable_shared_from_this<X> {
public:
  void f()
  {
    print_share(shared_from_this());
  }

  void print()
  {
    std::cout << "X" << std::endl;
  }
};

int main()
{
  boost::shared_ptr<X> p(new X());
  p->setup_shared_from_this(p);

  p->f();
}
