// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <type_traits>
#include <utility>

template <int N>
struct int_ {};

template <bool B>
struct bool_ {};

struct cont {};
struct end {};

template <bool Cond>
auto is_end(bool_<Cond>)
  -> typename std::conditional<Cond, end, cont>::type;

// 再帰テンプレート
template <class T, int N>
auto add_pointers_impl(T, int_<N>, cont)
  -> decltype(add_pointers_impl(
                std::declval<T*>(),
                int_<N-1>(),
                std::declval<decltype(
                  is_end(bool_<N - 1 == 0>())
                )>()
              ));

template <class T, int N>
auto add_pointers_impl(T, int_<N>, end)
  -> T;

template <class T, int N>
auto add_pointers(T, int_<N>)
  -> decltype(add_pointers_impl(
                std::declval<T>(),
                int_<N>(),
                std::declval<decltype(
                  is_end(bool_<N == 0>())
                )>()));

int main()
{
    typedef decltype(
      add_pointers(std::declval<int>(), int_<3>())
    ) result;
    static_assert(std::is_same<result, int***>::value, "");
}

