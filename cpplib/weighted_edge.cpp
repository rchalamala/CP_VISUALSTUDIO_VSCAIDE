// Verification:
//

#include "weighted_edge.h"

template <typename T>
WeightedEdge<T>::WeightedEdge(const std::size_t& u_to, const T& u_weight)
    : Edge{u_to}, weight{u_weight} {}