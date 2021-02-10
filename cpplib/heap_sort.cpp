// Verification:
//

#include "heap_sort.h"

#include <algorithm>
#include <iterator>

template <typename Iterator,
          typename Comparator =
              std::less<typename std::iterator_traits<Iterator>::value_type>>
void heap_sort(Iterator first, Iterator last,
               Comparator compare) {
  std::make_heap(first, last, compare);
  std::sort_heap(first, last, compare);
}