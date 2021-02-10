#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <algorithm>
#include <iterator>

template <typename Iterator, typename Comparator>
void quick_sort(Iterator first, Iterator last, Comparator compare);

#endif
