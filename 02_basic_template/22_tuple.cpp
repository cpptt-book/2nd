// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;

void printType()
{
  cout << endl;
}

template <class Thead, class... Tbody>
void printType(Thead head, Tbody... body)
{
  cout << '(' << typeid(Thead).name() << ')' << head;
  if (sizeof...(body) > 0) cout << ',';
  printType(body...);
}

/*
 * tuple<T0, T1, T2...>
 */
template <int N, class... Ts> 
struct tuple_data;

// [1]
template <int N> 
struct tuple_data<N> {};

// [2]
template <int N, class Thead, class... Tbody>
struct tuple_data<N, Thead, Tbody...> : public tuple_data<N + 1, Tbody...> {
  Thead value;
};

// [3]
template <class... Ts> 
struct tuple : public tuple_data<0, Ts...> {};

/*
  struct tuple<○, △, □>
    : tuple_data<0, ○, △, □> {}
      : tuple_data<1, △, □>   { ○ value; }
        : tuple_data<2, □>     { △ value; }
          : tuple_data<3>       { □ value; }
*/

/* 
 * tuple<...> の N番目要素の参照 : get<N>() 
 */
template <int N, class Thead, class... Tbody>
Thead& get_tuple_data(tuple_data<N, Thead, Tbody...>& t)
{
  return t.value;
}

template <int N, class... Ts>
auto get(tuple<Ts...>& t) -> decltype(get_tuple_data<N>(t))
{
  return get_tuple_data<N>(t);
}

int main()
{
  tuple<char, int, const char*> t;
  get<0>(t) = 'T';
  get<1>(t) = 4;
  get<2>(t) = "two";
  printType(get<0>(t), get<1>(t), get<2>(t));
}
