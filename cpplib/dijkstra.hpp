#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

// Verification:
//

#include <cstddef>
#include <queue>
#include <type_traits>
#include <utility>
#include <vector>

#include "graph.hpp"

template <typename Edge, typename T>
std::pair<std::vector<T>, std::vector<std::size_t>> dijkstra(
    const Graph<Edge>& graph, const std::size_t& source) {
  static_assert(std::is_integral<T>::value);
  assert(0 <= source && source < graph.size());
  std::vector<T> costs(graph.size(), std::numeric_limits<T>::max());
  std::vector<std::size_t> parent(graph.size(),
                                  std::numeric_limits<std::size_t>::max());
  std::priority_queue<std::pair<T, std::size_t>,
                      std::vector<std::pair<T, std::size_t>>,
                      std::greater<std::pair<T, std::size_t>>>
      next;
  std::vector<bool> visited(graph.size(), false);
  costs[source] = 0;
  parent[source] = source;
  next.emplace(costs[source], source);
  while (!next.empty()) {
    std::size_t top = next.top().second;
    next.pop();
    if (!visited[top]) {
      visited[top] = true;
      for (const auto& neighbor : graph[top])
        if (!visited[neighbor.to] &&
            costs[neighbor.to] > costs[top] + neighbor.weight) {
          costs[neighbor.to] = costs[top] + neighbor.weight;
          parent[neighbor.to] = top;
          next.emplace(costs[neighbor.to], neighbor.to);
        }
    }
  }
  return std::make_pair(costs, parent);
}

template <typename Edge, typename T>
void dijkstra(const Graph<Edge>& graph, const std::size_t& source,
              std::vector<T>& costs, std::vector<std::size_t>& parent) {
  static_assert(std::is_integral<T>::value);
  assert(costs.size() == graph.size());
  assert(parent.size() == graph.size());
  assert(0 <= source && source < graph.size());
  std::priority_queue<std::pair<T, std::size_t>,
                      std::vector<std::pair<T, std::size_t>>,
                      std::greater<std::pair<T, std::size_t>>>
      next;
  std::vector<bool> visited(graph.size(), false);
  costs[source] = 0;
  parent[source] = source;
  next.emplace(costs[source], source);
  while (!next.empty()) {
    std::size_t top = next.top().second;
    next.pop();
    if (!visited[top]) {
      visited[top] = true;
      for (const auto& neighbor : graph[top])
        if (!visited[neighbor.to] &&
            costs[neighbor.to] > costs[top] + neighbor.weight) {
          parent[neighbor.to] = top;
          next.emplace(costs[neighbor.to] = costs[top] + neighbor.weight,
                       neighbor.to);
        }
    }
  }
}

#endif