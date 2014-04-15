// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <vector>
#include <list>
#include <deque>

using namespace std;

template <class ValueType>
class container_holder {
  std::vector<ValueType> vec_;
public:
  void push_back(const ValueType& value)
  {
    vec_.push_back(value);
  }

  template <class T>
  operator T() const
  {
    return T(std::begin(vec_), std::end(vec_));
  }
};

int main()
{
  container_holder<int> c;

  c.push_back(1);
  c.push_back(2);
  c.push_back(3);

  // container_holderから標準コンテナへの変換
  std::vector<int> v  = c; // OK
  std::list<int>   ls = c; // OK
  std::deque<int>  d  = c; // OK
}
