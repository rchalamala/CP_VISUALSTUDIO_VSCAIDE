#ifndef BIT_H
#define BIT_H

#include <cstddef>
#include <vector>

template <class T>
class BIT {
  std::vector<T> m_tree;

 public:
  explicit BIT(const std::size_t& size);

  void update(std::size_t i, const T& delta);

  T query(std::size_t i);

  T query(const std::size_t& i, const std::size_t& j);
};

#endif