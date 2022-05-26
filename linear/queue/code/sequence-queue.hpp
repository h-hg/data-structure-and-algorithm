#include "queue.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class SequenceQueue: public Queue<T> {
protected:
  T *_v = nullptr, *_capacity = nullptr, *_head = nullptr, *_tail = nullptr;
  void expand();
  size_t capacity() const;
public:
  SequenceQueue();
  virtual ~SequenceQueue();
  size_t size() const;
  T& front();
  T& back();
  void pop();
  void push(T const &val);
};

template <typename T>
SequenceQueue<T>::SequenceQueue() {
  const int n = 16;
  _tail = _head = _v = new T[16];
  _capacity = _v + n;
}

template <typename T>
SequenceQueue<T>::~SequenceQueue() {
  delete[] _v;
}

template <typename T>
inline size_t SequenceQueue<T>::capacity() const {
  return _capacity - _v;
}

template <typename T>
inline size_t SequenceQueue<T>::size() const {
  return _tail - _head;
}

template <typename T>
void SequenceQueue<T>::pop() {
  if(_head == _tail)
    return;
  ++_head;
}

template <typename T>
T& SequenceQueue<T>::front() {
  return *_head;
}

template <typename T>
void SequenceQueue<T>::push(T const &val) {
  expand();
  *_tail++ = val;
}

template <typename T>
T& SequenceQueue<T>::back() {
  return *(_tail - 1);
}

template <typename T>
void SequenceQueue<T>::expand() {
  if(_tail != _capacity)
    return;
  size_t use_size = size();
  size_t capacity_size = capacity();
  if(use_size < capacity_size / 2) {
    //move the element
    copy(_head, _tail, _v);
    _head = _v;
    _tail = _head + use_size;
  } else {
    //malloc a new space
    size_t new_capacity = capacity_size * 2;
    T *new_v = new T[new_capacity];
    copy(_head, _tail, new_v);
    delete[] _v;
    _v = _head = new_v;
    _tail = _head + use_size;
    _capacity = _v + new_capacity;
  }
}