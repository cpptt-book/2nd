// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

class integer {
  int data_;
public:
  integer(int data)
    : data_(data) {}

  template <class T>
  operator T() const
  {
    return data_;
  }
};

int main()
{
  integer value = 3;

  int    n = value; // value.operator int()
  double d = value; // value.operator double()
  char   c = value; // value.operator char()
}
