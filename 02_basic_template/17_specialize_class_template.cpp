// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <string>

// プライマリテンプレート
template <class T>
class printer {
public:
  void out(const T& value) const
  {
    std::cout << value;
  }
};

// std::string に対する特殊化
template <>
class printer<std::string> {
public:
  void out(const std::string& value) const
  {
    // 文字列は "" で囲む
    std::cout << '"' << value << '"';
  }
};

int main()
{
  printer<int>().out(3);
  std::cout << std::endl;
  printer<std::string>().out("hello");
}
