// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>

template <template <class> class Pred,
          class Head, class... Tail>
struct any_of {
  static const bool value = Pred<Head>::value ?
                            true :
                            any_of<Pred, Tail...>::value;
};

template <template <class> class Pred,
          class Head>
struct any_of<Pred, Head> {
  static const bool value = Pred<Head>::value;
};


template <class T>
struct is_int {
  static const bool value = false;
};

template <>
struct is_int<int> {
  static const bool value = true;
};

int main()
{
  {
    const bool result = any_of<is_int, char, double, int>::value;
    static_assert(result, "include int");
  }
  {
    const bool result = any_of<is_int, char, double, void>::value;
    static_assert(!result, "not include int");
  }
}
