// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <bool Cond, class Then, class Else>
struct if_;

template <class Then, class Else>
struct if_<true, Then, Else> {
  typedef Then type;
};

template <class Then, class Else>
struct if_<false, Then, Else> {
  typedef Else type;
};

int main()
{
  if_<true, int, long>::type value1;
  if_<false, int, long>::type value2;
}
