// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <string>

struct debug_log {
  static void print(const std::string& value)
  {
    std::cout << value << std::endl;
  }
};

struct release_log {
  static void print(const std::string&) {}
};

template <class LogPolicy = debug_log>
struct hoge {
  void foo() const
  {
    LogPolicy::print("Fatal Error!!!");
  }
};

int main()
{
  hoge<debug_log>().foo();
  hoge<release_log>().foo();
  hoge<>().foo();

  typedef hoge<debug_log> default_hoge;
  default_hoge().foo();
}
