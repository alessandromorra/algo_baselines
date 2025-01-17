#ifndef SORT_QUICK_SORT_H_
#define SORT_QUICK_SORT_H_

#include <vector>

inline vector<int>::iterator partition(
    const vector<int>::iterator begin, const vector<int>::iterator end) {
  const auto pivot = begin;
  auto bound = pivot;
  auto it = pivot + 1;

  while (it < end) {
    if (*it < *pivot) {
      ++bound;
      std::iter_swap(bound, it);
    }
    ++it;
  }

  ++it;
  std::iter_swap(bound, pivot);
  return bound;
}

inline void quickSortRecursive(
    const vector<int>::iterator begin, const vector<int>::iterator end) {
  if (end - begin <= 1) { return; }

  const auto pivot = partition(begin, end);
  quickSortRecursive(begin, pivot);
  quickSortRecursive(pivot + 1, end);
}

// Sort by recursively partitioning array into elements smaller and bigger than
// pivot.
// T~O(N*log(N)), S~O(log(N))
inline vector<int> quickSort(const vector<int>& data) {
  if (data.empty()) { return data; }
  if (data.size() == 1) { return data; }

  vector<int> d = data;
  quickSortRecursive(d.begin(), d.end());
  return d;
}

#endif  // SORT_QUICK_SORT_H_
