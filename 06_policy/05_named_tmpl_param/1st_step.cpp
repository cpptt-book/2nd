// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include "named_tmpl_param.hpp"

template <class Strategy>
struct ownership {
  typedef Strategy type;
};

struct reference_count {};
struct deep_copy {};


template <bool IsMultiThread>
struct multi_thread {
  static const bool value = IsMultiThread;
};


template <class>
struct is_ownership_policy {
  static const bool value = false;
};

template <class Strategy>
struct is_ownership_policy<ownership<Strategy>> {
  static const bool value = true;
};

template <class>
struct is_multi_thread_policy {
  static const bool value = false;
};

template <bool IsMultiThread>
struct is_multi_thread_policy<multi_thread<IsMultiThread>> {
  static const bool value = true;
};

template <class... Args>
struct smart_ptr {
  typedef typename
    get_required_arg<
      is_ownership_policy,
      Args...
    >::type
  ownership_policy;

  typedef typename
    get_optional_arg<
      multi_thread<false>,
      is_multi_thread_policy,
      Args...
    >::type
  multi_thread_policy;
};

int main()
{
  smart_ptr<multi_thread<true>, ownership<reference_count>> p;

  static_assert(
    std::is_same<
      decltype(p)::ownership_policy,
      ownership<reference_count>
    >::value,
    "ownership policy is not reference_count");

  static_assert(
    std::is_same<
      decltype(p)::multi_thread_policy,
      multi_thread<true>
    >::value,
    "multi thread policy is not multi_thread<true>");
}
