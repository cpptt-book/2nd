// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <vector>
#include <iostream>

class iterator_holder {
  typedef std::vector<int>::iterator value_type;
  value_type iter_;
public:
  iterator_holder(value_type iter) : iter_(iter) {}

  value_type& get() { return iter_; }

  operator bool() const
  {
    return false;
  }
};

#define FOR_EACH(Value, Container) \
  if      (iterator_holder begin_ = std::begin(Container)) {} \
  else if (iterator_holder end_   = std::end(Container)) {} \
  else for (bool continue_ = true; \
            begin_.get() != end_.get(); \
            ++begin_.get()) \
    if ((continue_ = false) == true) {} \
    else for (Value = *begin_.get(); \
              continue_ == false; \
              continue_ = true)

int main()
{
  std::vector<int> v = {1, 2, 3};

  FOR_EACH (int item, v) {
    std::cout << item << std::endl;
  } // 1, 2, 3 が順に出力される
}
