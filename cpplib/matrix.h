#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <vector>

template<class T> class Matrix
{
	std::vector<std::vector<T>> m_matrix;

public:
	explicit Matrix(const std::size_t& n, const std::size_t& m);

	explicit Matrix(const std::vector<std::vector<T>>& u_matrix);

	void set(const std::size_t& i, const std::size_t& j, const T& element);

	void make_identity();
};

#endif
