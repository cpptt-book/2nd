// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

template <class T>
class equal_comparable {
  // T クラスのoperator==を使ってoperator!=を定義
  friend bool operator!=(const T& lhs, const T& rhs)
    { return !lhs.operator==(rhs); }
};

class hoge : private equal_comparable<hoge> {
  int id_;
public:
  explicit hoge(int id) : id_(id) {}

  bool operator==(const hoge& rhs) const
    { return id_ == rhs.id_; }
};

int main()
{
  hoge h1(1);
  hoge h2(2);
  
  bool is_equal     = h1 == h2;
  bool is_not_equal = h1 != h2;
}
