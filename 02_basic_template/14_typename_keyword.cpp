// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

struct X {
  typedef int result;
  result f();
//……
};

struct Y {
  static const int result = 5;
//……
};

int p;

template <class T>
void g(T arg)
{
  typename T::result* p;
//……
}

int main()
{
  g(X()); // OK
//g(Y()); // コンパイルエラー！Yはresult型を持っていない
}
