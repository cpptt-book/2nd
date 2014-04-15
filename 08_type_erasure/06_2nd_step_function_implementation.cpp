// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_pointer.hpp>

using boost::mpl::if_;
using boost::is_pointer;

union any_pointer {
  void (*func_ptr)(); // 関数ポインタ
  void* obj_ptr;      // 関数オブジェクト
};

template <class Func, class R>
struct function_ptr_manager {
  static R invoke(any_pointer function_ptr)
  {
    Func func = reinterpret_cast<Func>(function_ptr.func_ptr);
    return func();
  }

  static void destroy(any_pointer) {}
};

template <class Func, class R>
struct function_obj_manager {
  static R invoke(any_pointer func_obj)
  {
    Func* func = reinterpret_cast<Func*>(func_obj.obj_ptr);
    return (*func)();
  }

  static void destroy(any_pointer function_obj_ptr)
  {
    Func* func =
      reinterpret_cast<Func*>(function_obj_ptr.obj_ptr);
    delete func;
  }
};

struct function_ptr_tag {}; // 関数ポインタ
struct function_obj_tag {}; // 関数オブジェクト

template <class Func>
struct get_function_tag {
  typedef typename if_<is_pointer<Func>,
    function_ptr_tag,
    function_obj_tag>
  ::type type;
};

template <class Signature>
class function;

template <class R>
class function<R()> {
  R (*invoke_)(any_pointer);
  void (*destroy_)(any_pointer);
  any_pointer functor_;
public:
  function()
    : invoke_(0), destroy_(0) {}

  ~function()
  {
    clear();
  }

  template <class Func>
  function& operator=(Func func)
  {
    typedef typename get_function_tag<Func>::type func_tag;
    assign_to(func, func_tag());
    return *this;
  }

  R operator()()
  {
    return invoke_(functor_);
  }

private:
  // set_function_ptr()をassign_to()に名前変更して第2パラメータ追加
  template <class FuncPtr>
  void assign_to(FuncPtr func_ptr, function_ptr_tag)
  {
    clear();
    invoke_ = &function_ptr_manager<FuncPtr, R>::invoke;
    destroy_ = &function_ptr_manager<FuncPtr, R>::destroy;
    functor_.func_ptr = reinterpret_cast<void(*)()>(func_ptr);
  }

  // set_function_obj()をassign_to()に名前変更して第2パラメータ追加
  template <class FuncObj>
  void assign_to(FuncObj func_obj, function_obj_tag)
  {
    clear();
    invoke_ = &function_obj_manager<FuncObj, R>::invoke;
    destroy_ = &function_obj_manager<FuncObj, R>::destroy;
    functor_.obj_ptr =
      reinterpret_cast<void*>(new FuncObj(func_obj));
  }

  void clear()
  {
    if (destroy_)
      destroy_(functor_);
    destroy_ = 0;
  }
};

int func()
{
  return 3;
}

struct functor {
  int operator()() const
  {
    return 4;
  }
};

int main()
{
  function<int()> f;

  // 関数ポインタ
  f = &func;
  int func_result    = f(); // 3

  // 関数オブジェクト
  f = functor();
  int functor_result = f(); // 4
}
