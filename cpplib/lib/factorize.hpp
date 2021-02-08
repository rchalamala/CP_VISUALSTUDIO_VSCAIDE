#ifndef FACTORIZE_HPP
#define FACTORIZE_HPP

// https://github.com/yosupo06/library-checker-problems/blob/master/math/factorize/sol/correct.cpp
// Verification:
//

#include <cmath>
#include <type_traits>
#include <vector>

#include "pollards_rho.hpp"

template <typename T>
std::vector<T> factorize(const T& n) {
  static_assert(std::is_integral<T>::value);
  assert(n >= 0);
  if (n == 1) return std::vector<T>();
  T factor = pollards_rho<T>(n);
  if (n == factor) return std::vector<T>{n};
  std::vector<T> original{factorize(factor)}, divided{factorize(n / factor)};
  original.insert(original.end(), divided.begin(), divided.end());
  return original;
}

#endif