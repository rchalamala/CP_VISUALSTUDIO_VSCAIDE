// Verification:
//

#include "bit.h"

#include <cassert>
#include <cstddef>
#include <type_traits>
#include <vector>

template <typename T>
BIT<T>::BIT(const std::size_t& size) {
  static_assert(std::is_integral<T>::value);
  m_tree.assign(size + 1, 0);
}

template <typename T>
void BIT<T>::update(std::size_t i, const T& delta) {
  assert(i >= 0);
  for (++i; i < m_tree.size(); i += i & -i) m_tree[i] += delta;
}

template <typename T>
T BIT<T>::query(std::size_t i) {
  assert(i < m_tree.size());
  T sum = 0;
  for (++i; i; i -= i & -i) sum += m_tree[i];
  return sum;
}

template <typename T>
T BIT<T>::query(const std::size_t& i, const std::size_t& j) {
  return query(j) - (i ? query(i - 1) : 0);
}