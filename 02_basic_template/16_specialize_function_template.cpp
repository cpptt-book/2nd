// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <cstring> // strcmp

template <class T>
bool equal(T x, T y)
{
  return x == y;
}

template <>
bool equal(const char* x, const char* y)
{
  return std::strcmp(x, y) == 0;
}

int main()
{
  int n = 3;
  const char* s = "C++";
  std::cout << std::boolalpha;
  std::cout << equal(n, 2) << std::endl;
  std::cout << equal(n, 3) << std::endl;
  std::cout << equal(s, "Java") << std::endl;
  std::cout << equal(s, "C++") << std::endl;
}
