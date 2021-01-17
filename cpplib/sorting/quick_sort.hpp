#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

// Verification:
//

#include <algorithm>
#include <iterator>

template<typename Iterator, typename Comparator = std::less<typename std::iterator_traits<Iterator>::value_type>> void quick_sort(Iterator first, Iterator last, Comparator compare = Comparator())
{
	if(first != last)
	{
		auto midpoint = std::next(first, distance(first, last) / 2);
		auto pivot = std::max(std::min(*first, *midpoint), std::min(std::max(*first, *midpoint), *std::prev(last)));
		Iterator left = std::partition(first, last, [&compare, &pivot](const auto& element) -> bool { return compare(element, pivot); });
		Iterator right = std::partition(left, last, [&pivot](const auto& element) -> bool { return pivot == element; });
		quick_sort(first, left, compare);
		quick_sort(right, last, compare);
	}
}

#endif