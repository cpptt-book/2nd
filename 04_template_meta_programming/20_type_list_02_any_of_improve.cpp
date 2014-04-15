// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <tuple>

template <template <class> class Pred, class List>
struct any_of_impl;

template <template <class> class Pred,
          class Head, class... Tail>
struct any_of_impl<Pred, std::tuple<Head, Tail...>> {
  static const bool value = Pred<Head>::value ?
                            true :
                            any_of_impl<
                              Pred,
                              std::tuple<Tail...>
                            >::value;
};

template <template <class> class Pred>
struct any_of_impl<Pred, std::tuple<>> {
  static const bool value = false;
};

template <template <class> class Pred,
          class... List>
struct any_of {
  static const bool value =
      any_of_impl<Pred, std::tuple<List...>>::value;
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
  {
    const bool result = any_of<is_int>::value;
    static_assert(!result, "not include int");
  }
}
