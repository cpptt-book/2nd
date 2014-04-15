// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <int N>
struct factorial {
  static const int value = N * factorial<N - 1>::value;
};

template <>
struct factorial<0> {
  static const int value = 1;
};

int main()
{
  const int result = factorial<3>::value;
  static_assert(result == 6, "result is 6");
}
