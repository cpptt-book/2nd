// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T, int N = 10>
class Stack {
  T   data_[N];
  int index_;
public:
  Stack() : index_(0) {}
  ~Stack() {}
  void push(T x)
    { if (index_ < N) data_[index_++] = x; }
  T top() const
    { return data_[index_ - 1]; }
  void pop()
    { if (index_ > 0) --index_; }
};

// 3種のStackを使う……
int main()
{
  Stack<int, 5>  istack;
  Stack<long, 8> lstack;
  Stack<void*>   pstack; // 省略時は10
//……
}

