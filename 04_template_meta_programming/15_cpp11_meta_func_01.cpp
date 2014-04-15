// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <type_traits>

/* メタ関数適用
template <class T>
T* add_pointer();

int main()
{
    typedef decltype(add_pointer<int>()) result;
    static_assert(std::is_same<result, int*>::value, "");
}
*/

// 再帰テンプレート
template <class T, int N>
struct add_pointer_t {
    typedef typename add_pointer_t<T*, N - 1>::type type;
};

template <class T>
struct add_pointer_t<T, 0> {
    typedef T type;
};

template <class T, int N>
typename add_pointer_t<T, N>::type add_pointer();

int main()
{
    typedef decltype(add_pointer<int, 3>()) result;
    static_assert(std::is_same<result, int***>::value, "");
}
