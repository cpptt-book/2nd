// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T>
struct remove_const {
  typedef T type;
};

template <class T>
struct remove_const<const T> {
  typedef T type;
};

template <class T>
struct remove_volatile {
  typedef T type;
};

template <class T>
struct remove_volatile<volatile T> {
  typedef T type;
};

template <class T>
struct remove_cv {
  typedef typename remove_volatile<
    typename remove_const<T>::type
  >::type type;
};

int main()
{
  remove_cv<const volatile int>::type value = 3;
}
