// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <vector>
#include <algorithm>

template <class T, template <class> class ComparePolicy>
class sorted_vector {
  std::vector<T> vec_;
public:
  void push_back(const T& value)
  {
    vec_.push_back(value);
    std::sort(std::begin(vec_), std::end(vec_),
              &ComparePolicy<T>::compare);
  }

  void print()
  {
    for (const T& x : vec_) {
      std::cout << x << std::endl;
    }
  }
};

template <class T>
struct less_policy {
  static bool compare(const T& lhs, const T& rhs)
  {
    return lhs < rhs;
  }
};

template <class T>
struct greater_policy {
  static bool compare(const T& lhs, const T& rhs)
  {
    return lhs > rhs;
  }
};

int main()
{
  sorted_vector<int, less_policy> v;

  v.push_back(3);
  v.push_back(1);
  v.push_back(4);

  v.print();
}
