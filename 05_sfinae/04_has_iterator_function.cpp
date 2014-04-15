// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T>
constexpr bool has_iterator_impl(typename T::iterator*)
{
  return true;
}

template <class T>
constexpr bool has_iterator_impl(...)
{
  return false;
}

template <class T>
constexpr bool has_iterator()
{
  return has_iterator_impl<T>(nullptr);
}

#include <vector>
int main()
{
  static_assert(
    has_iterator<std::vector<int>>(),
    "vectorはiterator型を持っている");

  static_assert(
    !has_iterator<int>(),
    "intはiterator型を持っていない");
}
