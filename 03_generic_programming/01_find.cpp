// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <vector>
#include <list>
#include <iterator>

template <class Iterator, class T>
Iterator find(Iterator first, Iterator last, const T& value)
{
  while (first != last) {
    if (*first == value)
      break; // 見つかった！

      ++first;
  }
  return first;
}

using namespace std;
int main()
{
  char arr[] = "hello";
  vector<int> v = {1, 2, 3};
  list<long> ls = {1L, 2L, 3L};

  char* p = ::find(begin(arr), end(arr), 'e');
  if (p != end(arr)) { /* 見つかった */ }

  decltype(v)::iterator itv = ::find(begin(v), end(v), 3);
  if (itv != end(v)) { /* 見つかった */ }

  decltype(ls)::iterator itls = ::find(begin(ls), end(ls), 3);
  if (itls != end(ls)) { /* 見つかった */ }
}
