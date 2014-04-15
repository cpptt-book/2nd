// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

struct integer {
  int data_;
public:
  integer(int data = 0)
    : data_(data) {}

  operator bool() const
  {
    return false;
  }
};

int main()
{
  if      (integer n1 = 1) {}
  else if (integer n2 = 2) {}
  else if (integer n3 = 3) {}
  else {
    n1;
    n2;
    n3;
  }
}
