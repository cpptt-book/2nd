// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

// InputIterator版: “ひとつ進む”を繰り返す(あと戻り不可)
template <class InputIterator, class Distance>
void _advance(InputIterator& iter, Distance offset,
              input_iterator_tag)
{
  for (; 0 < offset; --offset)
    ++iter;
}

// ForwardIterator版: “ひとつ進む”を繰り返す(あと戻り不可)
template <class ForwardIterator, class Distance>
void _advance(ForwardIterator& iter, Distance offset,
              forward_iterator_tag)
{
  for (; 0 < offset; --offset)
    ++iter;
}

// BidirectionalIterator版: “ひとつ進む/ 戻る”を繰り返す
template <class BidirectionalIterator, class Distance>
void _advance(BidirectionalIterator& iter, Distance offset,
              bidirectional_iterator_tag)
{
  if (offset > 0){
    // offsetが正のとき、“ひとつ進む”を繰り返す
    for (; 0 < offset; --offset)
    ++iter;
  }
  else {
    // offsetが負のとき、“ひとつ戻る”を繰り返す
    for (; offset < 0; ++offset)
      --iter;
  }
}

// RandomAccessIterator版: operator+=で一気にジャンプ
template <class RandomAccessIterator, class Distance>
void _advance(RandomAccessIterator& iter, Distance offset,
              random_access_iterator_tag)
{
  iter += offset;
}

template <class Iterator, class Distance>
void advance(Iterator& iter, Distance offset)
{
  _advance(iter, offset,
    typename iterator_traits<Iterator>::iterator_category());
}

int main()
{
  vector<int> vec = {1, 2, 3};
  list<int>   lst = {1, 2, 3};

  decltype(vec)::iterator vi = begin(vec);
  ::advance(vi, 2); // viを2進める

  decltype(lst)::iterator li = begin(lst);
  ::advance(li, 3); // liを3進める
}
