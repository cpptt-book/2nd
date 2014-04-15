// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class Iterator>
void selection_sort(Iterator first, Iterator last)
{
  for (Iterator p = first; p != last; ++p) {
    Iterator min_position = p;
    for (Iterator q = p; q != last; ++q) {
      if (*min_position > *q) {
        min_position = q;
      }
    }
    auto tmp = *min_position;
    *min_position = *p;
    *p = tmp;
  }
}

template <class Iterator, class Compare>
void selection_sort(Iterator first, Iterator last, Compare comp)
{
  for (Iterator p = first; p != last; ++p) {
    Iterator min_position = p;
    for (Iterator q = p; q != last; ++q) {
      if (comp(*q, *min_position)) {
        min_position = q;
      }
    }
    auto tmp = *min_position;
    *min_position = *p;
    *p = tmp;
  }
}

#include <iostream>
#include <functional>
#include <iterator>

int main()
{
  int data[] = { 9, 7, 5, 3, 1, 8, 6, 4, 2, 0 };

  selection_sort(std::begin(data), std::end(data), std::greater<int>());
  for (int x : data) {
    std::cout << x << ' ';
  }
  std::cout << std::endl;
}
