// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <tuple>
#include <type_traits>

template <class Head, class... Tail>
struct g {
  typedef Head head;
  typedef std::tuple<Tail...> tail;
};

template <class... List>
struct f {
  typedef typename g<List...>::head head;
  typedef typename g<List...>::tail tail;
};

typedef f<int, char, double> list;

static_assert(std::is_same<
  list::head,
  int
>::value, "head must be int");

static_assert(std::is_same<
  list::tail,
  std::tuple<char, double>
>::value, "tail must be tuple<char, double>");

int main() {}

