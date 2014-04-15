// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/ordered_index.hpp>

using namespace boost::multi_index;

template <class T>
using SeqContainer = multi_index_container<
  T,
  indexed_by<sequenced<>>
>;

template <class T>
using OrdContainer = multi_index_container<
  T,
  indexed_by<ordered_unique<identity<T>>>
>;

int main()
{
  SeqContainer<int> seq;
  seq.push_back(3);
//seq.insert(1); // コンパイルエラー！
                 // insert()メンバ関数はを持っていない

  OrdContainer<int> ord;
  ord.insert(3);
//ord.push_back(1); // コンパイルエラー！
                    // push_back()メンバ関数を持っていない
}
