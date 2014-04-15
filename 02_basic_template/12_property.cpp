// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

/*
N1615: C++ Properties -- a Library Solution
http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2004/n1615.pdf
より抜粋
*/

template <class T, class Object,       // プロパティの型、オーナーの型
          T (Object::*real_getter)()const,    // get 関数
          T (Object::*real_setter)(const T&)> // set 関数
class RWProperty {
  Object* my_object;
public:
  // プロパティのオーナー（所有者） を設定
  void operator()(Object* obj) { my_object = obj; }
  // 関数呼び出しによるget／set
  T operator()() const
    { return (my_object->*real_getter)(); }
  T operator()(const T& value)
    { return (my_object->*real_setter)(value); }
  // メンバ関数get／set
  T get() const
    { return (my_object->*real_getter)(); }
  T set(const T& value)
    { return (my_object->*real_setter)(value); }
  // '='演算子によるアクセス
  operator T() const
    { return (my_object->*real_getter)(); }
  T operator=(const T& value)
    { return (my_object->*real_setter)(value); }
  typedef T value_type;
};

#include <iostream>
#include <string>

using namespace std;

class Cat {
private:
  int    age_;
  string name_;
  int set_age(const int& age) { return age_ = age; }
  int get_age()const { return age_; }
  string set_name(const string& name) { return name_ = name; }
  string get_name()const { return name_; }
public:
  RWProperty<int, Cat, &Cat::get_age, &Cat::set_age> age;
  RWProperty<string, Cat, &Cat::get_name, &Cat::set_name> name;
  Cat() { age(this); name(this); }
};

int main()
{
  Cat aCat;
  aCat.age = 4;
  aCat.name = "tama";
  int age = aCat.age;
  string name = aCat.name;
  cout << name << " is " << age << " years old.\n";
}
