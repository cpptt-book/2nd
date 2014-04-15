// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <type_traits>

struct has_iterator_impl {
  template <class T>
  static std::true_type check(typename T::iterator*);

  template <class T>
  static std::false_type check(...);
};

template <class T>
class has_iterator :
  public decltype(has_iterator_impl::check<T>(nullptr)) {};

#include <vector>
int main()
{
  static_assert(
    has_iterator<std::vector<int>>::value,
    "vectorはiterator型を持っている");

  static_assert(
    !has_iterator<int>::value,
    "intはiterator型を持っていない");
}
