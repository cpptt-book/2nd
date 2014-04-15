// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <vector>
#include <iterator>

template <class InputIterator, class OutputIterator>
OutputIterator
copy(InputIterator first, InputIterator last, OutputIterator out)
{
  while (first != last) {
    *out = *first;
    ++out;
    ++first;
  }
  return out;
}

using namespace std;

int main()
{
  vector<int> v = {1, 2, 3};

  vector<int> result(v.size()); // 十分な領域を用意しておく
  ::copy(begin(v), end(v), begin(result));

  for (int x : result) {
    cout << x << endl;
  }
}
