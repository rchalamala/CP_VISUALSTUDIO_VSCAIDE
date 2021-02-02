#ifndef BINARY_INSERTION_SORT
#define BINARY_INSERTION_SORT

#include <algorithm>
#include <iterator>

template <typename Iterator,
          typename Comparator =
              std::less<typename std::iterator_traits<Iterator>::value_type>>
void binary_insertion_sort(Iterator first, Iterator last,
                           Comparator compare = Comparator()) {
  for (Iterator i = first; i != last; ++i)
    std::rotate(std::upper_bound(first, i, *i, compare), i, std::next(i));
}

#endif