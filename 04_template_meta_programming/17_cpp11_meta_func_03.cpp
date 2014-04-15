// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <type_traits>
#include <utility>

template <int N>
struct int_ {};

// 再帰テンプレート
template <class T, int N,
  typename std::enable_if<(N > 0)>::type* = nullptr>
auto add_pointer(T, int_<N>) -> decltype(add_pointer(std::declval<T*>(), int_<N-1>()));

template <class T, int N,
  typename std::enable_if<N == 0>::type* = nullptr>
auto add_pointer(T, int_<N>) -> T;

int main()
{
  typedef decltype(
    add_pointer(std::declval<int>(), int_<3>())
  ) result;
  static_assert(std::is_same<result, int***>::value, "");
}
