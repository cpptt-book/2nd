// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <utility>

struct is_less_than_comparable_impl {
  template <class T, class U>
  static auto check(T*, U*) -> decltype(
    std::declval<T>() < std::declval<U>(),
    std::true_type());

  template <class T, class U>
  static auto check(...) -> std::false_type;
};

// 型Tと型Uがoperator<で比較可能か判定するメタ関数
template <class T, class U>
struct is_less_than_comparable
  : decltype(is_less_than_comparable_impl::check<T, U>(
                nullptr, nullptr
             )) {};

template <class T>
const T& min(const T& a, const T& b)
{
  // 型Tに対する要件
  static_assert(is_less_than_comparable<T, T>::value,
                "T must less than comparable");

  return a < b ? a : b;
}

class X {};

int main()
{
  int n = ::min(1, 2);
//X x = ::min(X(), X()); // コンパイルエラー！
                         // 型Xはoperator<で比較できない
}
