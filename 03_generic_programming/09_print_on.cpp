// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Plain {
public:
  virtual string convert(const string& str) const
    { return str; }
};

template <class Base = Plain>
class Bold : public Base {
public:
  using Base::Base; // コンストラクタを継承する(C++11)

  virtual string convert(const string& str) const
    { return "<b>" + Base::convert(str) + "</b>"; }
};

template <class Base = Plain>
class Italic: public Base {
public:
  using Base::Base;

  virtual string convert(const string& str) const
    { return "<i>" + Base::convert(str) + "</i>"; }
};

template <class Base = Plain>
class Size : public Base {
  string size_;
public:
  using Base::Base;

  Size(int s) { ostringstream strm; strm << s; size_ = strm.str(); }
  virtual string convert(const string& str) const
    { return "<font size='" + size_ + "'>" +
             Base::convert(str) + "</font>"; }
};

int main()
{
  Plain p;
  Bold<> b;
  Italic<> i;
  Size<Bold<Italic<>>> sbi(5); // 多重のパラメータ化継承
  Italic<Size<>> si(3);

  Plain* converter[5] = { &p, &b, &i, &sbi, &si };

  for (Plain* c : converter) {
    cout << c->convert("Hello, C++") << endl;
  }
}
