// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#ifndef TEMPLATE_TECHNIQUES_POLICY_FIND_IF_INCLUDE
#define TEMPLATE_TECHNIQUES_POLICY_FIND_IF_INCLUDE

#include <type_traits>

struct not_found {};

template <template <class> class Pred,
          class Head, class... Tail>
struct find_if_impl {
  typedef typename
    std::conditional<
      Pred<Head>::value,
      Head,
      typename find_if_impl<Pred, Tail...>::type
    >::type
  type;
};

template <template <class> class Pred, class Head>
struct find_if_impl<Pred, Head> {
  typedef typename
    std::conditional<
      Pred<Head>::value,
      Head,
      not_found
    >::type
  type;
};

template <template <class> class Pred, class... List>
struct find_if {
  typedef typename find_if_impl<Pred, List...>::type type;
};

#endif


