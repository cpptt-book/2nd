// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
	
template <class T, int N>
int size(T (&ar)[N])
{
  return N;
}

template <class T, int N>
T last_element(T (&ar)[N])
{
  return ar[N - 1];
}

int main()
{
  int data[] = { 1, 3, 5, 7, 9 };
  int n = size(data); // 5を返す
  int last = last_element(data); // data[4]を返す

  std::cout << n << std::endl;
  std::cout << last << std::endl;
}
