// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

class shared_deleter_base {
public:
  shared_deleter_base() {}
  virtual ~shared_deleter_base() {}
  virtual void destroy() = 0;
};

template <class T, class D>
class shared_deleter : public shared_deleter_base {
  T* object_;
  D deleter_;
public:
  shared_deleter(T* object, D deleter)
  : object_(object), deleter_(deleter) {}

  virtual void destroy()
  {
    deleter_(object_);
  }
};

template <class T>
class shared_ptr {
  T*                   object_;  // ポインタ
  shared_deleter_base* deleter_; // カスタム削除子
public:
  // カスタム削除子を使用しないコンストラクタ
  explicit shared_ptr(T* object) : object_(object), deleter_(0) {}

  // カスタム削除子を使用するコンストラクタ
  template <class D>
  shared_ptr(T* object, D deleter) : object_(object)
  {
    deleter_ = new shared_deleter<T, D>(object_, deleter);
  }

  ~shared_ptr()
  {
    // カスタム削除子が指定されていたらそれを実行
    if (deleter_) {
      deleter_->destroy();
      delete deleter_;
    }
    // カスタム削除子が指定されていなかったらdelete
    else {
      delete object_;
    }
  }

  T* operator->() const { return object_; }
};

#include <iostream>

using namespace std;

struct hoge {
  hoge() { cout << "コンストラクタ" << endl; }
  ~hoge() { cout << "デストラクタ" << endl; }
  void something() const { cout << "何かする" << endl; }
};

void delete_hoge(hoge* p)
{
  delete p;
  cout << "削除子を使用して解放" << endl;
}

void foo()
{
  shared_ptr<hoge> p(new hoge(), &delete_hoge);
  p->something();
}

int main()
{
  foo();
}
