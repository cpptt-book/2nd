// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

class drawable {
  struct vtable {
    void (*draw)(void*);
  };

  template <class T>
  struct vtable_initializer {
    static vtable vtbl_;

    static void draw(void* this_)
    {
      static_cast<T*>(this_)->draw();
    }
  };

  void* this_;
  vtable* vptr_;
public:
  template <class T>
  drawable(T& other)
    : this_(&other), vptr_(&vtable_initializer<T>::vtbl_) {}

  void draw() const
  {
    vptr_->draw(this_);
  }
};

template <class T>
drawable::vtable drawable::vtable_initializer<T>::vtbl_ = {
  &drawable::vtable_initializer<T>::draw
};

#include <iostream>
using namespace std;
struct circle { // 注：drawableを継承していない
  void draw() const
  {
    cout << "円を描画する" << endl;
  }
};

int main()
{
  circle c;
  drawable a = c;

  a.draw(); // OK
}
