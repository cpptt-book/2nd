// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>

using namespace std;

struct A {};
struct B {};

A foo_a() { cout << "call A" << endl; return A(); }
B foo_b() { cout << "call B" << endl; return B(); }

struct X {
  operator A() const { return foo_a(); }
  operator B() const { return foo_b(); }
};

int main()
{
  X x;
  static_cast<A>(x); // call A
  static_cast<B>(x); // call B
}
