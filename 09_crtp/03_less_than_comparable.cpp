// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T>
struct less_than_comparable {
  friend bool operator>(const T& lhs, const T& rhs)
  {
    return rhs.operator<(lhs);
  }

  friend bool operator<=(const T& lhs, const T& rhs)
  {
    return !rhs.operator<(lhs);
  }

  friend bool operator>=(const T& lhs, const T& rhs)
  {
    return !lhs.operator<(rhs);
  }
};

class hoge : private less_than_comparable<hoge> {
  int id_;
public:
  hoge(int id) : id_(id) {}

  bool operator<(const hoge& rhs) const
  {
    return id_ < rhs.id_;
  }
};

int main()
{
  hoge h1(1);
  hoge h2(2);
  bool is_less             = h1 < h2;
  bool is_greater          = h1 > h2;
  bool is_less_or_equal    = h1 <= h2;
  bool is_greater_or_equal = h1 >= h2;
}
