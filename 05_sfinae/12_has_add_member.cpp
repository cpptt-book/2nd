// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <utility>
#include <boost/utility/enable_if.hpp>

struct has_add_member_impl {
  template <class T, class U>
  static auto check(T*, U*) -> decltype(
    std::declval<T>().add(std::declval<U>()),
    std::true_type());

  template <class T, class U>
  static auto check(...) -> std::false_type;
};

template <class T, class U>
struct has_add_member
  : decltype(has_add_member_impl::check<T, U>(
			    nullptr, nullptr)) {};

// 関数テンプレートのoperator+。
// 型Tがadd()メンバ関数を持っている場合のみ呼び出せる。
template <class T, class U>
typename boost::enable_if<has_add_member<T, U>, T>::type
  operator+(const T& a, const U& b)
{
  return a.add(b);
}

class X {
  int value;
public:
  X(int value)
    : value(value) {}

  X add(const X& x) const
  {
    return X(value + x.value);
  }

  int getValue() const { return value; }
};

int main()
{
  X a(1);
  X b(2);

  X r = a + b;
  std::cout << r.getValue() << std::endl;
}
