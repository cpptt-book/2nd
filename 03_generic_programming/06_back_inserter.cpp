// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
  int data[] = { 1, 2, 3 };
  std::vector<int> v;

  std::copy(std::begin(data), std::end(data), std::back_inserter(v));
}
