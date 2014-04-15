// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <string>

template <class T>
class Util {
  T value_;
public:
  Util(const T& v);
  void add(const T& v);
  T get() const;
  int size() const;
};

template <class T>
Util<T>::Util(const T& v) : value_(v) {}

template <class T>
void Util<T>::add(const T& v) { value_ += v; }

template <class T>
T Util<T>::get() const { return value_; }

template <class T>
int Util<T>::size() const { return value_.size(); }


// クラス全体を明示的にインスタンス化する
// template class Util<int>; // コンパイルエラー！intはsize()メンバ関数を持っていない

// 個々のメンバ関数を明示的にインスタンス化する
// OK
template Util<int>::Util(const int&);
template void Util<int>::add(const int&);
template int Util<int>::get() const;

int main()
{
  Util<int> iu(12);
  iu.add(34);
  std::cout << iu.get() << std::endl;
  Util<std::string> su("hello, ");
  su.add("C++");
  std::cout << su.get() << std::endl;
}
