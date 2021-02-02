#ifndef DIGIT_SUM_HPP
#define DIGIT_SUM_HPP

// Verification:
//

#include <cassert>
#include <type_traits>

template <typename T>
T digit_sum(T n) {
  static_assert(std::is_integral<T>::value);
  assert(n >= 0);
  T result = 0;
  for (; n; result += n % 10, n /= 10)
    ;
  return result;
}

#endif