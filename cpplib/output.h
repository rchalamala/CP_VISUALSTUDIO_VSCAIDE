#ifndef OUTPUT_H
#define OUTPUT_H

#include <ostream>

template <typename Arg, typename... Args>
void print(std::ostream& out, const Arg& first, const Args&... rest);

template <typename Arg, typename... Args>
void printn(std::ostream& out, const Arg& first, const Args&... rest);

template <typename Arg, typename... Args>
void prints(std::ostream& out, const Arg& first, const Args&... rest);

template <typename T>
void print(std::ostream& out, const T& element);

inline void printn(std::ostream& out);

inline void prints(std::ostream& out);

#endif