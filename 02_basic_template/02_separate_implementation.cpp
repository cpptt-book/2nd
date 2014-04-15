// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T>
class Stack {
  T*  data_;
  int index_;
  int capacity_;
public:
  explicit Stack(int n);
  ~Stack();
  void push(T x);
  T top() const;
  void pop();
};

template <class T>
Stack<T>::Stack(int n) : capacity_(n), index_(0)
{
  data_ = new T[capacity_];
}

template <class T>
Stack<T>::~Stack()
{
  delete[] data_;
}

template <class T>
void Stack<T>::push(T x)
{
  if (index_ < capacity_) data_[index_++] = x;
}

template <class T>
T Stack<T>::top() const
{
  return data_[index_ - 1];
}

template <class T>
void Stack<T>::pop()
{
  if (index_ > 0)
    --index_;
}

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
