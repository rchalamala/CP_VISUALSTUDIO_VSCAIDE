#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

// Verification:
//

#include <algorithm>
#include <iterator>

template<typename Iterator, typename Comparator = std::less<typename std::iterator_traits<Iterator>::value_type>> void merge_sort(Iterator first, Iterator last, Comparator compare = Comparator())
{
	auto size = std::distance(first, last);
	if(size > 1)
	{
		Iterator midpoint = std::next(first, size / 2);
		merge_sort(first, midpoint, compare);
		merge_sort(midpoint, last, compare);
		std::inplace_merge(first, midpoint, last, compare);
	}
}

#endif