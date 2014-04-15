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

struct X {};
union Y {};

int main()
{
  static_assert(
    is_class<X>::value,
    "Xはクラス");

  static_assert(
    is_class<Y>::value,
    "Yはクラス");

  static_assert(
    !is_class<int>::value,
    "intはクラスではない");
}
