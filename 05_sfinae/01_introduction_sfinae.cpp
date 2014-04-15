// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
using namespace std;
struct widget {
  typedef int value_type;
};

template <class T>
void something(typename T::value_type*)
{
  cout << "value_typeを持っている" << endl;
}

template <class T>
void something(...)
{
  cout << "それ以外" << endl;
}

int main()
{
  something<widget>(0);
  something<int>(0);
}

/*
出力：
value_typeを持っている
それ以外
*/
