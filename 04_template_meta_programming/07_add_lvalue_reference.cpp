// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T>
struct add_const_lvalue_reference {
  typedef const T& type;
};

int main()
{
  int value = 3;
  add_const_lvalue_reference<int>::type cr = value;
}
