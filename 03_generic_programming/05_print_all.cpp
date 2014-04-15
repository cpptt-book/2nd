// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <vector>
#include <iterator>
#include <utility>

template <class Iterator>
void print_all(std::pair<Iterator, Iterator> iter_pair)
{
  while (iter_pair.first != iter_pair.second) {
    std::cout << *iter_pair.first << ' ';
    ++iter_pair.first;
  }
  std::cout << std::endl;
}

int main()
{
  int ar[] = { 1, 2, 4, 8, 16 };
  std::vector<int> v(std::begin(ar), std::end(ar));

  print_all(std::make_pair(std::begin(ar), std::end(ar)));
  print_all(std::make_pair(std::begin(v), std::end(v)));
}
