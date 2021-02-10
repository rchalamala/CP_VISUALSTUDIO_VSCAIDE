#ifndef COMPRESS_HPP
#define COMPRESS_HPP

// Verification:
//

#include <cstddef>
#include <map>
#include <set>
#include <vector>

template <typename T>
std::size_t compress(std::vector<T>& elements) {
  std::set<T> orderedElements;
  for (const auto& element : elements) orderedElements.insert(element);
  std::map<T, std::size_t> indices;
  std::size_t index = 0;
  for (const auto& element : orderedElements) indices[element] = index++;
  for (auto& element : elements) element = static_cast<T>(indices[element]);
  return index;
}

template <typename T>
std::size_t compress(std::vector<std::pair<T, T>>& elements) {
  std::set<T> orderedElements;
  for (const auto& element : elements) {
    orderedElements.insert(element.first);
    orderedElements.insert(element.second);
  }
  std::map<T, std::size_t> indices;
  std::size_t index = 0;
  for (const auto& element : orderedElements) indices[element] = index++;
  for (auto& element : elements) {
    element.first = static_cast<T>(indices[element.first]);
    element.second = static_cast<T>(indices[element.second]);
  }
  return index;
}

#endif