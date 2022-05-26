#include <cstddef>
template <typename T>
class Queue {
public:
  virtual ~Queue() {}
  virtual size_t size() const = 0;
  virtual T &front() = 0;
  virtual T &back() = 0;
  virtual void pop() = 0;
  virtual void push(T const&val) = 0;
};