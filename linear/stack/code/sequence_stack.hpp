#include <algorithm>
#include <iostream>
#include "stack.hpp"
using namespace std;

template <typename T>
class SequenceStack: public Stack<T> {
protected:
  T *_bottom = nullptr, *_top = nullptr, *_capacity = nullptr;
  size_t capacity() const;
  void expand();
public:
  SequenceStack();
  virtual ~SequenceStack();
  size_t size() const;
  void pop();
  void push(T const&val);
  T& top();
};

template <typename T>
size_t SequenceStack<T>::capacity() const {
  return _capacity - _bottom;
}

template <typename T>
size_t SequenceStack<T>::size() const {
  return _top - _bottom + 1;
}

template <typename T>
void SequenceStack<T>::expand() {
  if(_top + 1 != _capacity)
    return;
  size_t new_capacity = capacity() * 2;
  T *new_bottom = new T[new_capacity];
  copy(_bottom, _top + 1, new_bottom);
  //free
  delete[] _bottom;
  //update
  _capacity = new_bottom + new_capacity;
  _top = new_bottom + (_top - _bottom);
  _bottom = new_bottom;
}

template <typename T>
SequenceStack<T>::SequenceStack() {
  const int n = 16;
  _bottom = new T[n];
  _top = _bottom - 1;
  _capacity = _bottom + n;
}

template <typename T>
SequenceStack<T>::~SequenceStack() {
  delete[] _bottom;
}

template <typename T>
void SequenceStack<T>::push(T const &val) {
  expand();
  *(++_top) = val;
}

template <typename T>
void SequenceStack<T>::pop() {
  if(_top == _bottom - 1)
    return;
  --_top;
}

template <typename T>
T& SequenceStack<T>::top() {
  return *_top;
}