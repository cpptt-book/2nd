// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <int N>
struct increment {
  static const int value = N + 1;
};

int main()
{
  const int result = increment<3>::value;
  static_assert(result == 4, "result is 4");
}
