#ifndef INPUT_H
#define INPUT_H

#include<array>
#include<complex>
#include<istream>
#include<tuple>
#include<utility>
#include<vector>

inline bool read(std::istream& in, double& element);

inline bool read(std::istream& in, long double& element);

template<typename Arg, typename... Args> bool read(std::istream& in, Arg& first, Args& ... rest);

template<typename T, std::size_t Size> bool read(std::istream& in, std::array<T, Size>& elements);

template<typename T1, typename T2> bool read(std::istream& in, std::pair<T1, T2>& element);

template<typename T> bool read(std::istream& in, T& element);

template<typename T> bool read(std::istream& in, std::complex<T>& element);

template<typename T> bool read(std::istream& in, std::tuple<T, T, T, T, T, T>& element);

template<typename T> bool read(std::istream& in, std::tuple<T, T, T, T, T>& element);

template<typename T> bool read(std::istream& in, std::tuple<T, T, T, T>& element);

template<typename T> bool read(std::istream& in, std::tuple<T, T, T>& element);

template<typename T> bool read(std::istream& in, std::vector<T>& elements);

#endif