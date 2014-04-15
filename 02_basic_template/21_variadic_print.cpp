// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <typeinfo>

using namespace std;

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

int main()
{
  printType('T', 4, "two");
}

/* 実行結果
Visual C++:
  (char)T, (int)4,(char const*)two
g++:
  (c)T,(i)4,(PKc)two
*/
