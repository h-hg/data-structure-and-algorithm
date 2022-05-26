
#include <algorithm>
using namespace std;

template <typename T>
class Vector {
protected:
  T *_head = nullptr, *_tail = nullptr, *_capacity = nullptr;
  void expand(size_t new_need);
  
public:
  Vector();
  Vector(int n);
  Vector(int n, T const &val);
  T& operator[](size_t);
  void push_back(T const &val);
  void pop_back();
  size_t size() const;
  size_t capacity() const;
  virtual ~Vector();
};

template <typename T>
inline size_t Vector<T>::size() const {
  return _tail - _head;
}

template <typename T>
inline size_t Vector<T>::capacity() const {
  return _capacity - _head;
}

template <typename T>
void Vector<T>::expand(size_t new_need) {
  size_t new_capacity = capacity();
  if(new_capacity >= new_need)
    return;
  
  while(new_capacity <= new_need)
    new_capacity <<= 1;
  T *new_head = new T[new_capacity];
  copy(_head, _tail, new_head);
  //free
  delete[] _head;
  //update
  _capacity = new_head + new_capacity;
  _tail = new_head + (_tail - _head);
  _head = new_head;
}

template <typename T>
Vector<T>::Vector() {
  const int n = 16;
  _tail = _head = new T[n];
  _capacity = _head + n;
}

template <typename T>
Vector<T>::Vector(int n) {
  _head = new T[n];
  _capacity = _tail = _head + n;
}

template <typename T>
Vector<T>::Vector(int n, T const &val): Vector<T>(n) {
  fill(_head, _tail, val);
}

template <typename T>
Vector<T>::~Vector() {
  delete [] _head;
}

template <typename T>
void Vector<T>::push_back(T const &val) {
  expand(size() + 1);
  *_tail++ = val;
}

template <typename T>
void Vector<T>::pop_back() {
  if(_tail == _head)
    return;
  --_tail;
}

template <typename T>
inline T& Vector<T>::operator[](size_t i) {
  return _head[i];
}