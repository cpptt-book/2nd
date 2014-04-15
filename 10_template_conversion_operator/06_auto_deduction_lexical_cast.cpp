// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <string>
#include <sstream>

template <class To, class From>
To lexical_cast(From from)
{
  To result;
  std::stringstream ss;

  ss << from;
  ss >> result;

  return result;
}

template <class From>
class lexical_cast_t {
  From from_;
public:
  lexical_cast_t(From from)
    : from_(from) {}

  template <class To>
  operator To() const
  {
    return lexical_cast<To>(from_);
  }
};

template <class From>
lexical_cast_t<From> lexical(From from)
{
  return lexical_cast_t<From>(from);
}

int main()
{
  int         n = lexical("3"); // 文字列型を整数型に変換
  std::string s = lexical(314); // 整数型を文字列型に変換
}
