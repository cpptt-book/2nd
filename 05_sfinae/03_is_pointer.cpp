// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T>
struct is_pointer {
  static const bool value = false;
};

template <class T>
struct is_pointer<T*> {
  static const bool value = true;
};

#include <iostream>
using namespace std;

int main()
{
  cout << ::is_pointer<int>::value  << endl;
  cout << ::is_pointer<int*>::value << endl;
}

/*
出力：
0
1
*/

