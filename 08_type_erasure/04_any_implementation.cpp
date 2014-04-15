// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <typeinfo>

class any {
  struct holder_base {
    virtual ~holder_base() {}
    virtual holder_base* clone() const = 0;
    virtual const std::type_info& type() const = 0;
  };

  template <class T>
  struct holder : public holder_base {
    T value_;

    holder(const T& value)
      : value_(value) {}
    
    virtual holder_base* clone() const
    {
      return new holder(value_);
    }

    virtual const std::type_info& type() const
    {
      return typeid(T);
    }
  };

public:
  template <class T>
  any(const T& value)
    : content_(new holder<T>(value)) {}

  any(const any& other)
    : content_(other.content_ ? other.content_->clone() : 0) {}

  ~any()
  {
    delete content_;
  }

  template <class T>
  any& operator=(const T& value)
  {
    delete content_;
    content_ = new holder<T>(value);
    return *this;
  }

  any& operator=(const any& other)
  {
    delete content_;
    content_ = other.content_ ? other.content_->clone() : 0;
    return *this;
  }

  const std::type_info& type() const
  {
    return content_ ? content_->type() : typeid(void);
  }

  template <class T>
  const T& cast() const
  {
    return dynamic_cast<holder<T>&>(*content_).value_;
  }

private:
  holder_base* content_;
};

struct hoge {};

int main()
{
  any val = 3;
  val = hoge();
  if (val.type() == typeid(int)) {
    int value = val.cast<int>();
  }
  else if (val.type() == typeid(hoge)) {
    hoge h = val.cast<hoge>();
  }
}
