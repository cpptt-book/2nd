// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <tuple>
#include <type_traits>

template <class T>
struct add_reference {
  typedef T& type;
};

template <class T>
struct add_reference<T&> {
  typedef T& type;
};

template <template <class> class F, class... List>
struct transform {
  typedef std::tuple<typename F<List>::type...> type;
};

int main()
{
  typedef transform<
    add_reference,
    int, char, double
  >::type result;

  static_assert(std::is_same<
    result,
    std::tuple<int&, char&, double&>
  >::value, "result's all type must be reference");
}
