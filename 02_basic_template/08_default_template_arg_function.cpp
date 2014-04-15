// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

#include <iostream>
#include <iomanip>

template <class T = double> // 省略時はdoubleとみなす
T pi() { return T(3.1415926536); }

int main()
{
  float  x = pi<float>(); // 型の明示
  double y = pi<>();      // 省略時 : pi<double>()
  double z = pi();        // 同上

  std::cout << std::setprecision(10) << std::fixed;
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  std::cout << z << std::endl;
}
