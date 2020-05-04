  
#ifndef _SELECTSORT_H
#define _SELECTSORT_H
#include <algorithm>

template <typename T, template Compare>
void SelectSort(T ar[], int n, Compare cmp) {
	for(int i = 0;i < n;++i) {
		int index = i;
		for(int j = i + 1;j < n;++j)
			if(cmp(ar[j],ar[index]))
				index = j;
		std::swap(ar[index],ar[i]);
	}
}

template <typename ForwardIterator, typename Compare>
void selectSort(ForwardIterator first, ForwardIterator last, Compare cmp) {
  while(first != last) {
    auto iter = first, it = first;
    while(++iter != last)
      if(cmp(*iter, *it))
        it = iter;
    std::swap(*first++, *it);
  }
}

#endif