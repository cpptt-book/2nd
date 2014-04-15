// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

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
  void set_function_ptr(Func func_ptr)
  {
    clear();
    invoke_ = &function_ptr_manager<Func, R>::invoke;
    destroy_ = &function_ptr_manager<Func, R>::destroy;
    functor_.func_ptr = reinterpret_cast<void(*)()>(func_ptr);
  }

  template <class Func>
  void set_function_obj(Func func_obj)
  {
    clear();
    invoke_ = &function_obj_manager<Func, R>::invoke;
    destroy_ = &function_obj_manager<Func, R>::destroy;
    functor_.obj_ptr =
      reinterpret_cast<void*>(new Func(func_obj));
  }

  R operator()()
  {
    return invoke_(functor_);
  }

private:
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
  f.set_function_ptr(&func);
  int func_result    = f(); // 3

  // 関数オブジェクト
  f.set_function_obj(functor());
  int functor_result = f(); // 4
}
