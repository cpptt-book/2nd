// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>

class utility {
public:
  template <int N>
  int get(int arg)
  {
    return N + arg;
  }
};

template <class T>
int foo(T x, int n)
{
  return x.template get<3>(n);
}

int main()
{
  std::cout << foo(utility(), 2) << std::endl;
}
