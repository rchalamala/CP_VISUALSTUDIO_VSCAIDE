#ifndef LCM_HPP
#define LCM_HPP

// https://cp-algorithms.com/algebra/euclid-algorithm.html
// Verification:
//

#include <cmath>
#include <type_traits>

#include "gcd.hpp"

template <typename T>
T lcm(const T& u_a, const T& u_b) {
  static_assert(std::is_integral<T>::value);
  T a = std::abs(u_a), b = std::abs(u_b);
  return a / binary_gcd(a, b) * b;
}

#endif