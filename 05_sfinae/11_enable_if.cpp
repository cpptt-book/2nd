// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <type_traits>

struct is_class_impl {
  template <class T>
  static std::true_type check(int T::*);

  template <class T>
  static std::false_type check(...);
};

template <class T>
struct is_class :
  public decltype(is_class_impl::check<T>(nullptr)) {};

#include <iostream>
#include <boost/utility.hpp>

using namespace boost;

template <class T>
void check(T value, typename enable_if<is_class<T>>::type* = 0)
{
  std::cout << "Tはクラス" << std::endl;
}

template <class T>
void check(T value, typename disable_if<is_class<T>>::type* = 0)
{
  std::cout << "Tはクラスではない" << std::endl;
}

struct X {};

int main()
{
  check(X());
  check(3);
}
