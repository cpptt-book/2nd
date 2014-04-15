// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template <template<class T, class A = allocator<T>>
          class Container>
class Phonebook {
  struct Record {
    string name;
    string phone;
    Record(const string& n, const string& p) : name(n), phone(p) {}
    friend ostream& operator<<(ostream& stream, const Record& r)
    {
      return stream << r.name << ':' << r.phone;
    }
  };
  Container<Record> book;
public:
  void add(const string& name, const string& phone)
  {
    book.emplace_back(name,phone);
  }

  void print(ostream& stream) const
  {
    copy(begin(book), end(book),
         ostream_iterator<Record>(stream, "\n"));
  }
};

int main()
{
  Phonebook<vector> pb; // list,deque も指定可能
  pb.add("police", "110");
  pb.add("fire", "119");
  pb.add("weather", "177");
  pb.print(std::cout);
}
