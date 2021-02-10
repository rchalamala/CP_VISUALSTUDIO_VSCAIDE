// https://github.com/bqi343/USACO/blob/master/Implementations/content/contest/CppIO.h
// Verification:
//

#include "to_string.h"

#include <bitset>
#include <complex>
#include <string>
#include <utility>
#include <vector>

inline std::string std::to_string(const bool& element) {
#ifdef LOCAL
  return element ? "true" : "false";
#else
  return std::string{static_cast<char>('0' + element)};
#endif
}

inline std::string std::to_string(const char& element) {
  return std::string(1, element);
}

inline std::string std::to_string(const char* element) {
  return std::string(element);
}

inline std::string std::to_string(const std::string& element) {
  return element;
}

inline std::string std::to_string(const std::vector<bool>& elements) {
  std::string convert = "{";
  for (const auto&& element : elements)
    convert += static_cast<char>('0' + element);
  return convert + "}";
}

template <typename T>
std::string std::to_string(const T& elements) {
  std::string convert;
  bool first = true;
#ifdef LOCAL
  convert += "{";
  for (const T& element : elements) {
    if (!first) convert += ", ";
    first = false;
    convert += std::to_string(element);
  }
  convert += "}";
#else
  for (const T& element : elements) {
    if (!first) convert += " ";
    first = false;
    convert += std::to_string(element);
  }
#endif
  return convert;
}

template <std::size_t Size>
std::string std::to_string(const std::bitset<Size>& elements) {
  return elements.to_string();
}

template <typename T>
std::string std::to_string(const std::complex<T>& element) {
  std::stringstream convert;
  convert << element;
  return convert.str();
}

template <typename T1, typename T2>
std::string std::to_string(std::pair<T1, T2> element) {
#ifdef LOCAL
  return "(" + std::to_string(element.first) + ", " +
         std::to_string(element.second) + ")";
#else
  return std::to_string(element.ff) + " " + std::to_string(element.ss);
#endif
}