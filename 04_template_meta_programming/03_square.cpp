// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <int N>
struct square {
  static const int value = N * N;
};

int main()
{
  const int result = square<3>::value;
  static_assert(result == 9, "result is 9");
}
