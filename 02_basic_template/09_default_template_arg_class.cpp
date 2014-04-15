// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <iomanip>

template <class X = double, class Y = char, class Z = Y>
struct xyz {
  X x;
  Y y;
  Z z;
};

int main()
{
  xyz<> s0; //　→　xyz<double, char, char>
  xyz<int> s1; //　→　xyz<int, char, char>
  xyz<int, long> s2; //　→　xyz<int, long, long>
  xyz<int, long, int> s3; //　→　xyz<int, long, int>
}
