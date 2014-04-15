// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <utility>

struct is_addable_impl {
  template <class T, class U>
  static auto check(T*, U*) -> decltype(
    std::declval<T>() + std::declval<U>(),
    std::true_type());

  template <class T, class U>
  static auto check(...) -> std::false_type;
};

template <class T, class U>
struct is_addable
  : decltype(is_addable_impl::check<T, U>(
               nullptr, nullptr)) {};

struct A {};

struct B {};
B operator+(const B&, const B&) { return B(); }

int main()
{
  static_assert(!is_addable<A, A>::value, "A must be not addable");
  static_assert( is_addable<B, B>::value, "B must be addable");
  static_assert( is_addable<int, double>::value, "int/double must be addable");

  std::cout << std::boolalpha;
  std::cout << is_addable<A, A>::value << std::endl;
  std::cout << is_addable<B, B>::value << std::endl;
  std::cout << is_addable<int, double>::value << std::endl;
}

