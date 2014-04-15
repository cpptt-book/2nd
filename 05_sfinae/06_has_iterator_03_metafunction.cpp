// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T>
class has_iterator {
  typedef char yes;
  typedef struct { char a[2]; } no;

  template <class U>
  static yes check(typename U::iterator*);

  template <class U>
  static no check(...);

public:
  static const bool value = sizeof(check<T>(0)) == sizeof(yes);
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
