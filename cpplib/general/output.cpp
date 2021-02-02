// Verification:
//

#include "output.h"

template <typename T>
void print(std::ostream& out, const T& element) {
  out << std::to_string(element);
}

inline void printn(std::ostream& out) { print(out, '\n'); }

inline void prints(std::ostream& out) { print(out, '\n'); }

template <typename Arg, typename... Args>
void print(std::ostream& out, const Arg& first, const Args&... rest) {
  print(out, first);
  print(out, rest...);
}

template <typename Arg, typename... Args>
void printn(std::ostream& out, const Arg& first, const Args&... rest) {
  print(out, first);
  if (sizeof...(rest)) prints(out);
  printn(out, rest...);
}

template <typename Arg, typename... Args>
void prints(std::ostream& out, const Arg& first, const Args&... rest) {
  print(out, first);
  if (sizeof...(rest)) print(out, " ");
  prints(out, rest...);
}