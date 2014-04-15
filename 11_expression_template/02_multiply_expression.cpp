// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <cstddef>

template <class L, class R>
class plus {
  const L& l_;
  const R& r_;
public:
  plus(const L& l, const R& r)
    : l_(l), r_(r) {}

  float operator[](size_t i) const
  {
    return l_[i] + r_[i];
  }
};

template <class L, class R>
class multiply {
  const L& l_;
  const R& r_;
public:
  multiply(const L& l, const R& r)
    : l_(l), r_(r) {}

  float operator[](size_t i) const
  {
    return l_[i] * r_[i];
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
  plus<L, R> operator+(const L& lhs, const R& rhs)
  {
    return plus<L, R>(lhs, rhs);
  }

  template <class L, class R>
  multiply<L, R> operator*(const L& lhs, const R& rhs)
  {
    return multiply<L, R>(lhs, rhs);
  }
} // namespace math

int main()
{
  math::vector x, y, z, t;
  t = x + y * z;
}
