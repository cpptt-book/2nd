// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>

template <class T>
class Stack {
  T*  data_;
  int index_;
  int capacity_;
public:
  explicit Stack(int n);
  ~Stack();
  void push(T x);

  template <class U>
  void top(U& dst) const;

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
template <class U>
void Stack<T>::top(U& dst) const
{
  dst = data_[index_ - 1];
}

template <class T>
void Stack<T>::pop()
{
  if (index_ > 0)
    --index_;
}

int main()
{
  const int n = 1;
  Stack<char> s(n);
  s.push('A');

  int i;
  long l;

  s.top(i);
  s.top(l);

  std::cout << static_cast<char>(i) << std::endl;
  std::cout << static_cast<char>(l) << std::endl;
}
