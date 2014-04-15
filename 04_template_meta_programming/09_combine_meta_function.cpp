// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T>
struct add_const {
  typedef const T type;
};

template <class T>
struct add_lvalue_reference {
  typedef T& type;
};

template <class T>
struct add_lvalue_reference<T&> {
  typedef T& type;
};

template <class T>
struct add_const_lvalue_reference {
  typedef
    typename add_const<
      typename add_lvalue_reference<T>::type
    >::type
  type;
};

int main()
{
  int value = 3;
  add_const_lvalue_reference<int>::type cr = value; // cr : const int&
}
