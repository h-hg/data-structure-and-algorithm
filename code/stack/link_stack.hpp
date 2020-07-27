#include <cstdlib>
using namespace std;

template <typename T>
class LinkStack: public Stack<T> {
protected:
  struct Node {
    T val;
    Node* next;
    Node(T const &v, Node *p = nullptr): val(v), next(p) {}
  };
  Node *_bottom = nullptr, *_top = nullptr;
  size_t _size;
public:
  LinkStack();
  virtual ~LinkStack();
  size_t size() const;
  T& top();
  void pop();
  void push(T const &val);
};

template <typename T>
LinkStack<T>::LinkStack() {
  _bottom = _top = new Node(T());
  _size = 0;
}

template <typename T>
LinkStack<T>::~LinkStack() {
 Node *tmp = nullptr;
 while(_top != _bottom) {
   tmp = _top -> next;
   delete _top;
   _top = tmp;
 }
 delete _bottom; 
}

template <typename T>
inline size_t LinkStack<T>::size() const {
  return _size;
}

template <typename T>
inline T& LinkStack<T>::top() {
  return _top -> val;
}

template <typename T>
void LinkStack<T>::pop() {
  if(_top == _bottom)
    return;
  Node *tmp = _top -> next;
  delete _top;
  _top = tmp;
  --_size;
}

template <typename T>
void LinkStack<T>::push(T const &val) {
  _top = new Node(val, _top);
  ++_size;
}