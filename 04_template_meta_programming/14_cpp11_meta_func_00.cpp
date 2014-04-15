// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <type_traits>
#include <utility>

template <class T>
T* add_pointer(T);

int main()
{
    typedef decltype(add_pointer(std::declval<int>())) result;
    static_assert(std::is_same<result, int*>::value, "");
}

