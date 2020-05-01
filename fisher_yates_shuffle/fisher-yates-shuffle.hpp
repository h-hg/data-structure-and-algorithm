#ifndef _FISHER_YATES_SHUFFLE_H
#define _FISHER_YATES_SHUFFLE_H
#include <algorithm>
#include <ctime>
#include <cstdlib>

static auto _ = []() {
  srand(time(0));
};

// return random number in [minVal, maxVal]
int random(int minVal, int maxVal) {
  return rand() % (maxVal - minVal + 1) + minVal;
}

template <typename RAIter>
void shuffle(RAIter begin, RAIter end) {
  for(--end; end != begin; --end) {
    int k = random(0, end - begin);
    std::swap(*(begin + k), *end);
  }
}

#endif