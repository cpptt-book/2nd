// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <vector>

template <int... List>
std::vector<int> initializer()
{
  std::vector<int> v = { List... };
  return v;
}

int main()
{
  std::vector<int> v = initializer<1, 2, 3>();

  for (int x : v) {
    std::cout << x << std::endl;
  }
}
