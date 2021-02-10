#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <algorithm>
#include <iterator>

template <typename Iterator, typename Comparator>
void merge_sort(Iterator first, Iterator last, Comparator compare);

#endif
