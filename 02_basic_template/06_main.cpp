// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include "06_stack.h"

int main()
{
  Stack<int> s(10);
  s.push(1);
  s.push(2);
  while (s.size() != 0) {
    std::cout << s.top() << std::endl;
    s.pop();
  }
}
