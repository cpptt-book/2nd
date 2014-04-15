// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <type_traits>
#include <utility>

struct is_assignable_impl {
  template <class T>
  static auto check(T*) -> decltype(
    std::declval<T&>() = std::declval<const T&>(),
    std::true_type());

  template <class T>
  static auto check(...) -> std::false_type;
};

template <class T>
struct is_assignable
  : decltype(is_assignable_impl::check<T>(nullptr)) {};

struct A {
  A& operator=(const A&) = delete;
};

struct B {};

int main()
{
  static_assert(!is_assignable<A>::value, "Aは代入不可");
  static_assert( is_assignable<B>::value, "Bは代入可能");
}

