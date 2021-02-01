#ifndef POLLARDS_RHO_HPP
#define POLLARDS_RHO_HPP

// Verification:
//

#include "../general/prng.hpp"
#include "gcd.hpp"
#include "miller_rabin.hpp"
#include "modular.hpp"
#include <type_traits>

template<typename T> T pollards_rho(const T& n)
{
	static_assert(std::is_integral<T>::value);
	if (n % 2 == 0) return 2;
	if (miller_rabin<T>(n)) return n;
	MODULUS::value = n;
	auto f = [](const T& x) -> T { return static_cast<T>((VariableModulus(x) ^ 2) + 1); };
	T x = getUID<T>(0, n - 1), y = f(x), divisor = 1;
	while (divisor == 1)
	{
		x = f(x);
		y = f(f(y));
		divisor = binary_gcd(x - y, n);
		if (divisor == n || x == y) return pollards_rho(n);
	}
	return divisor;
}

#endif