// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <vector>
#include <iterator>

template <class Iterator, class Predicate>
Iterator find_if(Iterator first, Iterator last, Predicate pred)
{
  while (first != last) {
    if (pred(*first))
      break; // 見つかった!

    ++first;
  }
  return first;
}

// 値が偶数か判定する関数オブジェクト
struct is_even {
  bool operator()(int x) const
  { return x % 2 == 0; }
};

using namespace std;

int main()
{
  vector<int> v = {1, 2, 3};

  decltype(v)::iterator it = ::find_if(begin(v), end(v), is_even());
  if (it != end(v)) { // 見つかった
    cout << *it << endl;
  }
}
