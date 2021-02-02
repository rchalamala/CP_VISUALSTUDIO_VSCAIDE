// Verification:
//

#include "weighted_edge.h"

template <typename T>
WeightedEdge<T>::WeightedEdge(const std::size_t& u_to, const T& weight)
    : Edge{u_to}, weight{u_weight} {}