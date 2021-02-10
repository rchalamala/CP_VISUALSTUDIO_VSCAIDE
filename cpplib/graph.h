#ifndef GRAPH_H
#define GRAPH_H

#include <cstddef>
#include <initializer_list>
#include <vector>

template <class Edge>
class Graph {
  std::vector<std::vector<Edge>> graph;

 public:
  explicit Graph(const std::size_t& N);

  template <typename... Args>
  void add_edge(const std::size_t& from, const std::size_t& to, Args&... args);

  void extend();

  std::size_t size() const noexcept;

  bool empty() const noexcept;

  template <typename InputIterator>
  void assign(InputIterator first, InputIterator last);

  void assign(const std::size_t& N, const std::vector<Edge>& value);

  void assign(const std::initializer_list<std::vector<Edge>>& elements);

  auto begin() noexcept;

  auto begin() const noexcept;

  auto end() noexcept;

  auto end() const noexcept;

  auto rbegin() noexcept;

  auto rbegin() const noexcept;

  auto rend() noexcept;

  auto rend() const noexcept;

  auto cbegin() const noexcept;

  auto cend() const noexcept;

  auto crbegin() const noexcept;

  auto crend() const noexcept;

  auto& operator[](const std::size_t& at);

  const auto& operator[](const std::size_t& at) const;

  auto& at(const std::size_t& at);

  const auto& at(const std::size_t& at) const;

  auto& front();

  const auto& front() const;

  auto& back();

  const auto& back() const;

  void clear() noexcept;

  void resize(const std::size_t& N);

  void resize(const std::size_t& N, const std::vector<Edge>& value);
};

#endif