#ifndef KOSARAJUS_SCCS_HPP
#define KOSARAJUS_SCCS_HPP

// Verification:
//

#include "base/graph.hpp"
#include <cstddef>
#include <functional>
#include <stack>
#include <vector>

template<class Edge> std::vector<std::vector<std::size_t>> kosarajus_sccs(const Graph<Edge>& graph)
{
	std::vector<bool> visited(graph.size());
	std::stack<std::size_t> order;
	std::function<void(std::size_t)> dfs = [&](const std::size_t& at) -> void
	{
		visited[at] = true;
		for(const auto& neighbor : graph[at])
			if(!visited[neighbor.to])
				dfs(neighbor.to);
		order.push(at);
	};
	Graph<Edge> transposed(graph.size());
	for(std::size_t i = 0; i < graph.size(); ++i)
	{
		if(!visited[i]) dfs(i);
		for(const auto& neighbor : graph[i]) transposed.addEdge(neighbor.to, i);
		std::vector<std::vector<std::size_t>> sCCs;
	}
	std::vector<std::vector<std::size_t>> sCCs;
	std::function<void(std::size_t)> transposedDFS = [&](const std::size_t& at) -> void
	{
		visited[at] = false;
		sCCs.back().push_back(at);
		for(const auto& neighbor : graph[at])
			if(visited[neighbor.to])
				transposedDFS(neighbor.to);
	};
	while(!order.empty())
	{
		std::size_t i = order.top();
		order.pop();
		if(visited[i])
		{
			sCCs.emplace_back();
			transposedDFS(i);
		}
	}
	return sCCs;
}

#endif