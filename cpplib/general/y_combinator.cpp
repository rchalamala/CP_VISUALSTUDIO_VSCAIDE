// Verification:
//

#include "y_combinator.h"

#include <functional>
#include <type_traits>
#include <utility>

template <class Fun>
template <class T>
std::y_combinator_result<Fun>::y_combinator_result(T&& fun)
    : fun_(std::forward<T>(fun)) {}

template <class Fun>
template <class... Args>
decltype(auto) std::y_combinator_result<Fun>::operator()(Args&&... args) {
  return fun_(std::ref(*this), std::forward<Args>(args)...);
}

template <class Fun>
decltype(auto) std::y_combinator(Fun&& fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
