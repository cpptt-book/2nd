// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <cstddef>

template <class L, class Op, class R>
class expression {
  const L& l_;
  const R& r_;
public:
  expression(const L& l, const R& r)
    : l_(l), r_(r) {}

  float operator[](size_t i) const
  {
    return Op::apply(l_[i], r_[i]);
  }
};

struct plus {
  static float apply(float l, float r)
  {
    return l + r;
  }
};

struct multiply {
  static float apply(float l, float r)
  {
    return l * r;
  }
};

namespace math {
  class vector {
  public:
    static const int N = 3; // 次元数

    vector()
    {
      for (size_t i = 0; i < N; ++i) {
        values_[i] = 0;
      }
    }

    vector(const vector& rhs)
    {
      for (size_t i = 0; i < N; ++i) {
        values_[i] = rhs[i];
      }
    }

    template <class E>
    vector& operator=(const E& rhs)
    {
      for (size_t i = 0; i < N; ++i) {
        values_[i] = rhs[i];
      }
      return *this;
    }

    float& operator[](size_t i)       { return values_[i]; }
    float  operator[](size_t i) const { return values_[i]; }

  private:
    float values_[N];
  };

  template <class L, class R>
  expression<L, plus, R> operator+(const L& lhs, const R& rhs)
  {
    return expression<L, plus, R>(lhs, rhs);
  }
  
  template <class L, class R>
  expression<L, multiply, R> operator*(const L& lhs, const R& rhs)
  {
    return expression<L, multiply, R>(lhs, rhs);
  }
} // namespace math

int main()
{
  math::vector x, y, z, t;
  t = x + y * z;
}
