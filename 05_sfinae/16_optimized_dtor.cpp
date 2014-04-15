// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/has_trivial_destructor.hpp>

template <class T,
          typename boost::enable_if<
            boost::has_trivial_destructor<T>
          >::type* = nullptr>
void destroy_all(T*, T*)
{
  std::cout << "don't destroy" << std::endl;
}

template <class T,
          typename boost::disable_if<
            boost::has_trivial_destructor<T>
          >::type* = nullptr>
void destroy_all(T* first, T* last)
{
  std::cout << "loop destroy" << std::endl;
  while (first != last) {
    first->~T();
    ++first;
  }
}

#include <string>
#include <memory>

template <class T>
void construct_all(T* first, T* last)
{
  while (first != last) {
    new (first) T();
    ++first;
  }
}

template <class T>
void f()
{
  std::allocator<T> alloc;

  std::size_t size = 3;
  T* ar = alloc.allocate(size, nullptr);
  construct_all(ar, ar + size);

  // 全ての要素に対してデストラクタを呼び出す
  destroy_all(ar, ar + size);

  alloc.deallocate(ar, size);
}

int main()
{
  f<std::string>();
  f<int>();
}
