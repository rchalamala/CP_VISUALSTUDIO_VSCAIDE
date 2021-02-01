// https://github.com/bqi343/USACO/blob/master/Implementations/content/contest/CppIO.h
// Verification:
//

#include "to_string.hpp"
#include <iostream>
#include <string>

template<typename Arg, typename... Args> void debug(const Arg& first, const Args& ... rest)
{
	std::cerr << std::to_string(first);
	if (sizeof...(rest)) std::cerr << ", ";
	debug(rest...);
}

inline void debug() { std::cerr << "]" << std::endl; }