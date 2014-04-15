// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <int X, int N>
struct pow {
  static const int value = X * pow<X, N - 1>::value;
};

template <int X>
struct pow<X, 0> {
  static const int value = 1;
};

int main()
{
  const int result = pow<2, 3>::value;
  static_assert(result == 8, "result is 8");
}
