// Verification:
//

#include "matrix.h"

#include <cstddef>
#include <vector>

template <class T>
Matrix<T>::Matrix(const std::size_t& n, const std::size_t& m) : m_matrix{ n, std::vector<T>(m, 0) } {}

template <class T>
Matrix<T>::Matrix(const std::vector<std::vector<T>>& u_matrix) : m_matrix{ u_matrix } {}

template <class T>
void Matrix<T>::set(const std::size_t& i, const std::size_t& j, const T& element)
{
	assert(i >= 0 && i < m_matrix.size() && j >= 0 && j < m_matrix.front().size());
	m_matrix[i][j] = element;
}


template <class T>
void Matrix<T>::make_identity()
{
	assert(m_matrix.size() == m_matrix.front().size());
	for (std::size_t i = 0; i < m_matrix.size(); ++i) {
		m_matrix[i][i] = 1;
	}
}

template <class T>
Matrix<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs) {

}