# 哈夫曼树

把一年前写的哈夫曼树的代码给丢了，现在重新看了，顺便用容器重新实现一遍，感觉代码少了很多。

哈夫曼树也称最优二叉树，本质上是一种贪心思想。

关于哈夫曼树的介绍，有空再补上去。直接给出代码。

定义节点

```cpp
template <typneame T>
struct Node {
  T w;
  Node(T const &val):w(val){}
  virtual ~Node(){}
};

template <typename T>
struct LeafNode: public Node<T> {
  LeafNode(T const &val):Node<T>(val){}
};

template <typename T>
struct InnerNode:public Node<T> {
  Node<T> *lc, *rc;
  InnerNode(T const &val, Node<T> *plc = nullptr, Node<T>  *prc = nullptr):Node<T>(val), lc(plc), rc(prc){}
};
```

因为在树中使用的是指针，所以定义一个指针的比较函数。

```cpp
template <typename T>
struct Compare {
  bool operator()(const Node<T> * p1, const Node<T> *p2) {
    return p1->w > p2->w;
  }
};
```

不得不说使用优先级队列，代码量减少一半以上。
```cpp
template <typename T>
Node<T>* build(vector<T> &v) {
  //init
  priority_queue<Node<T>*, vector<Node<T>*>, Compare<T>> q;
  for(auto &val: v)
    q.push(new LeafNode<T>(val));
  //build
  while(q.size() > 1) {
    auto x = q.top();
    q.pop();
    auto y = q.top();
    q.pop();
    q.push(new InnerNode<T>(x->w + y->w, x, y));
  }
  return q.top();
}
```

测试一下吧，使用层级遍历，测试的代码比主体还长。

```cpp
template <typename T>
void levelVisit(Node<T> *root) {
  queue<Node<T> *> q;
  q.push(root);
  while(q.size()) {
    for(int i = 0, n = q.size(); i < n; ++i) {
      auto p = q.front();
      q.pop();
      cout << (p->w) << " ";
      auto p_cast = dynamic_cast<InnerNode<T>*>(p);
      if(p_cast != nullptr) {
        q.push(p_cast->lc);
        q.push(p_cast->rc);
      }
    }
    cout << endl;
  }
}
int main() {
  vector<int> v = {7, 19, 2, 6, 32, 3, 21, 10};
  auto root = build<int>(v);
  levelVisit<int>(root);
  return 0;
}
```
```
100
40 60
19 21 28 32
11 17
5 6 7 10
2 3
```

当然，撸oj的时候，肯定要牺牲空间换时间（写代码），类的继承一堆都删了吧，成就不到30行的哈夫曼树。

```cpp
template <typename T>
struct Node {
  T w;
  Node<T> *lc, *rc;
  Node(T const &val, Node<T> *plc = nullptr, Node<T> *prc = nullptr):w(val), lc(plc), rc(prc){}
};

template <typename T>
struct Compare {
  bool operator()(const Node<T> * p1, const Node<T> *p2) {
    return p1->w > p2->w;
  }
};

template <typename T>
Node<T>* build(vector<T> &v) {
  //init
  priority_queue<Node<T>*, vector<Node<T>*>, Compare<T>> q;
  for(auto &val: v)
    q.push(new Node<T>(val));
  //build
  while(q.size() > 1) {
    auto x = q.top();
    q.pop();
    auto y = q.top();
    q.pop();
    q.push(new Node<T>(x->w + y->w, x, y));
  }
  return q.top();
}
```

依旧测试一下

```cpp
template <typename T>
void levelVisit(Node<T> *root) {
  queue<Node<T> *> q;
  q.push(root);
  while(q.size()) {
    for(int i = 0, n = q.size(); i < n; ++i) {
      auto p = q.front();
      q.pop();
      cout << (p->w) << " ";
      if(p->lc != nullptr)
        q.push(p->lc);
      if(p->rc != nullptr)
        q.push(p->rc);
    }
    cout << endl;
  }
}
int main() {
  vector<int> v = {7, 19, 2, 6, 32, 3, 21, 10};
  auto root = build<int>(v);
  levelVisit<int>(root);
  return 0;
}
```

```
100
40 60
19 21 28 32
11 17
5 6 7 10
2 3
```