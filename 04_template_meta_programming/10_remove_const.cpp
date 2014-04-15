// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T>
struct remove_const {
  typedef T type;
};

template <class T>
struct remove_const<const T> {
  typedef T type;
};

int main()
{
  remove_const<const int>::type value = 3;
}
