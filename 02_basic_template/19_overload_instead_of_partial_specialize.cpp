// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>

template <class T>
void print(T value) { std::cout << value << std::endl; }   // ［1］

template <class T>
void print(T* value) { std::cout << *value << std::endl; } // ［2］

int main()
{
  int n = 123;
  print(n);  // ［1］が呼ばれる
  print(&n); // ［2］が呼ばれる
}
