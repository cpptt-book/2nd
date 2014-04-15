// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T> // パラメータで型Tを受け取って
struct identity {
  typedef T type;  // 型Tを返す
};

int main()
{
  identity<int>::type value;
}
