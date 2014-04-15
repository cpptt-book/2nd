// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <string>

#include <iostream>

template <class T>
class printer {
public:
  // 標準出力に出力
  void out(T value)
  {
    std::cout << value << std::endl;
  }
};

// ポインタに対する部分特殊化
template <class T>
class printer<T*> {
public:
  void out(T* value) const
  {
    std::cout << *value << std::endl;
  }
};

int main()
{
  printer<int*> prt; // 部分特殊化版がインスタンス化される
  int n = 123;
  prt.out(&n);       // &nが指す値（123）が出力される
}

