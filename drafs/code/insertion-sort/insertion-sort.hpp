#ifndef _INSERTION_SORT_H
#define _INSERTION_SORT_H
#include <algorithm>
template <typename T, Compare cmp>
void insert_sort(T ar[],int n, Compare cmp) {
	for(int i = 1;i < n;++i)
	  for(int j = i; j > 0 && cmp(ar[j],ar[j-1]);--j)
			std::swap(ar[j],ar[j-1]);
}

template <typename ForwardIterator, typename Compare>
void insertion_sort(ForwardIterator first, ForwardIterator last, Compare cmp) {
}

#endif