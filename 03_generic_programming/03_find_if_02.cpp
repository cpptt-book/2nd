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

using namespace std;

int main()
{
  vector<int> v = {1, 2, 3};

  decltype(v)::iterator it = ::find_if(begin(v), end(v), [](int x){
                               return x % 2 == 0;
                             });
  if (it != end(v)) { // 見つかった
    cout << *it << endl;
  }
}
