// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#ifndef TEMPLATE_TECHNIQUES_POLICY_NAMED_TEMPLATE_PARAM_INCLUDE
#define TEMPLATE_TECHNIQUES_POLICY_NAMED_TEMPLATE_PARAM_INCLUDE

#include <type_traits>
#include "./find_if.hpp"

template <template <class> class Pred, class... List>
struct get_required_arg {
  typedef typename find_if<Pred, List...>::type type;
  static_assert(!std::is_same<type, not_found>::value,
                "required policy not found");
};

template <class Opt, template <class> class Pred, class... List>
struct get_optional_arg {
private:
  typedef typename find_if<Pred, List...>::type result;
public:
  typedef typename
    std::conditional<
      !std::is_same<result, not_found>::value,
      result,
      Opt
    >::type
  type;
};

#define DEFINE_TYPE_NAMED_PARAM(param)       \
  template <class T>                         \
  struct param {                             \
    typedef T type;                          \
  };                                         \
                                             \
  template <class>                           \
  struct is_ ## param ## _policy {           \
    static const bool value = false;         \
  };                                         \
                                             \
  template <class T>                         \
  struct is_ ## param ## _policy<param<T>> { \
    static const bool value = true;          \
  };

#define DEFINE_BOOL_NAMED_PARAM(param)       \
  template <bool V>                          \
  struct param {                             \
    static const bool value = V;             \
  };                                         \
                                             \
  template <class>                           \
  struct is_ ## param ## _policy {           \
    static const bool value = false;         \
  };                                         \
                                             \
  template <bool V>                          \
  struct is_ ## param ## _policy<param<V>> { \
    static const bool value = true;          \
  };

#endif
