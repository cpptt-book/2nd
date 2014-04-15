// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T>
class has_iterator {
  template <class U>
  static constexpr bool check(typename U::iterator*)
  { return true; }

  template <class U>
  static constexpr bool check(...)
  { return false; }
public:
  static const bool value = check<T>(nullptr);
};

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
