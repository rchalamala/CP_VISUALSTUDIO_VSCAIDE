#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

template<typename Arg, typename... Args> void debug(const Arg& first, const Args& ... rest);

inline void debug();

#ifdef LOCAL
#define DEBUG(...) std::cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", debug(__VA_ARGS__)
#else
#define DEBUG(...) 0
#endif

#endif