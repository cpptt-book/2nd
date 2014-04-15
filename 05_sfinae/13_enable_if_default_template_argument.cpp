// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <boost/utility.hpp>
#include <boost/type_traits/is_class.hpp>

using namespace boost;

template <class T,
          typename enable_if<
            is_class<T>
          >::type* = nullptr>
void check(T value)
{
  std::cout << "Tはクラス" << std::endl;
}

template <class T,
          typename disable_if<
            is_class<T>
          >::type* = nullptr>
void check(T value)
{
  std::cout << "Tはクラスではない" << std::endl;
}

struct X {};

int main()
{
  check(X());
  check(3);
}
