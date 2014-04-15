// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T>
class Stack {
  T*  data_;
  int index_;
  int capacity_;
public:
  explicit Stack(int n) : capacity_(n), index_(0)
    { data_ = new T[capacity_]; }
  ~Stack()
    { delete[] data_; }
  void push(T x)
    { if (index_ < capacity_) data_[index_++] = x; }
  T top() const
    { return data_[index_ - 1]; }
  void pop()
    { if (index_ > 0) --index_; }
};

// 3種のStackを使う……
int main()
{
  Stack<int>   istack(5);
  Stack<long>  lstack(8);
  Stack<void*> pstack(10);
  istack.push(1);
  istack.push(2);
//……
}
