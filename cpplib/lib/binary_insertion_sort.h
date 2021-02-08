#ifndef BINARY_INSERTION_SORT_H
#define BINARY_INSERTION_SORT_H

#include <algorithm>
#include <iterator>

template <typename Iterator, typename Comparator>
void binary_insertion_sort(Iterator first, Iterator last, Comparator compare);

#endif
