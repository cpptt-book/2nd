// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T, class Allocator>
class Stack {
  T*  data_;
  int index_;
  int capacity_;
public:
  explicit Stack(int n) : capacity_(n), index_(0)
    {
      Allocator alloc;
      data_ = alloc.allocate(capacity_);
      for (int i = 0; i < capacity_; ++i) {
        alloc.construct(data_ + i);
      }
    }
  ~Stack()
    { delete[] data_; }
  void push(T x)
    { if (index_ < capacity_) data_[index_++] = x; }
  T top() const
    { return data_[index_ - 1]; }
  void pop()
    { if (index_ > 0) --index_; }
};

#include <memory>

template <class T>
using MyAllocator = std::allocator<T>;

// カスタムアロケータを使用するStack型
template <class T>
using MyStack = Stack<T, MyAllocator<T>>;

int main()
{
  // 要素型のみ後から指定する
  const int n = 3;
  MyStack<int> s(n);
}
