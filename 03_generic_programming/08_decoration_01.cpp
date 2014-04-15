// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <string>
#include <cassert>

using namespace std;

class Plain {
public:
  string convert(const string& str) const
    { return str; }
};

template <class Base>
class Bold : public Base {
public:
  string convert(const string& str) const
    { return "<b>" + Base::convert(str) + "</b>"; }
};

template <class Base>
class Italic: public Base {
public:
  string convert(const string& str) const
    { return "<i>" + Base::convert(str) + "</i>"; }
};

int main()
{
  Bold<Plain> b;
  string s1 = b.convert("Hello"); // <b>Hello</b>
  
  Italic<Plain> i;
  string s2 = i.convert("Hello"); // <i>Hello</i>
  
  Italic<Bold<Plain>> ib;
  string s3 = ib.convert("Hello"); // <i><b>Hello</b></i>

  assert(s1 == "<b>Hello</b>");
  assert(s2 == "<i>Hello</i>");
  assert(s3 == "<i><b>Hello</b></i>");
}
