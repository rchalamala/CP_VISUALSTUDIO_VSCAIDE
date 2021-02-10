#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

// Verification:
//

#include <cmath>
#include <cstddef>
#include <vector>

template <typename T,
	typename = std::enable_if<std::is_integral<
	typename std::decay<decltype(T::value)>::type>::value>>
	class Polynomial {
	std::vector<T> polynomial{};

	void trim();

	public:
		Polynomial(const std::vector<T>& coefficients);

		[[nodiscard]] std::size_t size() const noexcept;

		auto& operator[](const std::size_t& at);

		const auto& operator[](const std::size_t& at) const;

		Polynomial operator+=(const Polynomial& other);

		template <typename T1>
		Polynomial& operator+=(const T1& other);

		Polynomial operator-=(const Polynomial& other);

		template <typename T1>
		Polynomial& operator-=(const T1& other);
};

template <typename T>
Polynomial<T> operator+(const Polynomial<T>& lhs, const Polynomial<T>& rhs);

template <typename T1, typename T2>
Polynomial<T1> operator+(const Polynomial<T1>& lhs, T2 rhs);

template <typename T>
Polynomial<T> operator-(const Polynomial<T>& lhs, const Polynomial<T>& rhs);

template <typename T1, typename T2>
Polynomial<T1> operator-(const Polynomial<T1>& lhs, T2 rhs);

template <typename T>
Polynomial<T> operator*(const Polynomial<T>& lhs, const Polynomial<T>& rhs);

template <typename T1, typename T2>
Polynomial<T1> operator*(const Polynomial<T1>& lhs, T2 rhs);

template <typename T>
Polynomial<T> operator/(const Polynomial<T>& lhs, const Polynomial<T>& rhs);

template <typename T1, typename T2>
Polynomial<T1> operator/(const Polynomial<T1>& lhs, T2 rhs);

template <typename T1, typename T2>
Polynomial<T1> operator^(const Polynomial<T1>& lhs, T2 rhs);

template <typename T>
bool operator==(const Polynomial<T>& lhs, const Polynomial<T>& rhs);

template <typename T1, typename T2>
bool operator==(const Polynomial<T1>& lhs, T2 rhs);

template <typename T>
bool operator!=(const Polynomial<T>& lhs, const Polynomial<T>& rhs);

template <typename T1, typename T2>
bool operator!=(const Polynomial<T1>& lhs, T2 rhs);

#endif

#endif
