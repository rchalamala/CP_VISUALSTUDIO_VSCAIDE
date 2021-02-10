#ifndef DESOPO_PAPE_HPP
#define DESOPO_PAPE_HPP

// Verification:
//

#include <cstddef>
#include <queue>
#include <type_traits>
#include <utility>
#include <vector>

#include "graph.h"

template <typename Edge, typename T>
std::pair<std::vector<T>, std::vector<std::size_t>> desopo_pape(
    const Graph<Edge>& graph, const std::size_t& source) {
  static_assert(std::is_integral<T>::value);
  assert(0 <= source && source < graph.size());
  std::vector<T> costs(graph.size(), std::numeric_limits<T>::max());
  std::vector<std::size_t> parent(graph.size(),
                                  std::numeric_limits<std::size_t>::max());
  std::deque<std::size_t> next;
  std::vector<std::size_t> visited(graph.size(), 0);
  costs[source] = 0;
  parent[source] = source;
  next.push_back(source);
  while (!next.empty()) {
    std::size_t top = next.front();
    next.pop_front();
    visited[top] = 2;
    for (const auto& neighbor : graph[top])
      if (costs[neighbor.to] > costs[top] + neighbor.weight) {
        costs[neighbor.to] = costs[top] + neighbor.weight;
        parent[neighbor.to] = top;
        if (visited[neighbor.to] == 0) {
          visited[neighbor.to] = 1;
          next.push_back(neighbor.to);
        } else if (visited[neighbor.to] == 2) {
          visited[neighbor.to] = 1;
          next.push_front(neighbor.to);
        }
      }
  }
  return std::make_pair(costs, parent);
}

template <typename Edge, typename T>
std::pair<std::vector<T>, std::vector<std::size_t>> desopo_pape(
    const Graph<Edge>& graph, const std::size_t& source, std::vector<T>& costs,
    std::vector<std::size_t>& parent) {
  static_assert(std::is_integral<T>::value);
  assert(costs.size() == graph.size());
  assert(parent.size() == graph.size());
  assert(0 <= source && source < graph.size());
  std::deque<std::size_t> next;
  std::vector<std::size_t> visited(graph.size(), 0);
  costs[source] = 0;
  parent[source] = source;
  next.push_back(source);
  while (!next.empty()) {
    std::size_t top = next.front();
    next.pop_front();
    visited[top] = 2;
    for (const auto& neighbor : graph[top])
      if (costs[neighbor.to] > costs[top] + neighbor.weight) {
        costs[neighbor.to] = costs[top] + neighbor.weight;
        parent[neighbor.to] = top;
        if (visited[neighbor.to] == 0) {
          visited[neighbor.to] = 1;
          next.push_back(neighbor.to);
        } else if (visited[neighbor.to] == 2) {
          visited[neighbor.to] = 1;
          next.push_front(neighbor.to);
        }
      }
  }
  return std::make_pair(costs, parent);
}

#endif