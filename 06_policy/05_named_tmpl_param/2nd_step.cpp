// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include "named_tmpl_param.hpp"

DEFINE_TYPE_NAMED_PARAM(ownership)
DEFINE_BOOL_NAMED_PARAM(multi_thread)

struct reference_count {};
struct deep_copy {};

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
}
