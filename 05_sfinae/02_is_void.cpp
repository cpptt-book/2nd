// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T>
struct is_void {
  static const bool value = false;
};

template <>
struct is_void<void> {
  static const bool value = true;
};

#include <iostream>
using namespace std;

int main()
{
  cout << boolalpha;
  cout << ::is_void<void>::value  << endl;
  cout << ::is_void<int>::value   << endl;
  cout << ::is_void<char*>::value << endl;
}

/*
出力：
true
false
false
*/
