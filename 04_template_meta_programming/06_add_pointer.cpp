// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T>
struct add_pointer {
  typedef T* type;
};

int main()
{
  int value = 3;
  add_pointer<int>::type p = &value;
}
