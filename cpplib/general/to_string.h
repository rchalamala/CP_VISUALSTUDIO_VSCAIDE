#ifndef TO_STRING_H
#define TO_STRING_H

#include <bitset>
#include <complex>
#include <string>
#include <utility>
#include <vector>

namespace std
{

	inline std::string to_string(const bool& element);

	inline std::string to_string(const char& element);

	inline std::string to_string(const char* element);

	inline std::string to_string(const std::string& element);

	inline std::string to_string(const std::vector<bool>& elements);

	template<typename T> std::string to_string(const T& elements);

	template<std::size_t Size> std::string to_string(const std::bitset<Size>& elements);

	template<typename T> std::string to_string(const std::complex<T>& element);

	template<typename T1, typename T2> std::string to_string(std::pair<T1, T2> element);

}

#endif