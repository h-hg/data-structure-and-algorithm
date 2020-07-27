template <typename T>
class Stack {
public:
  virtual ~Stack(){};
  virtual size_t size() const = 0;
  virtual T &top() = 0;
  virtual void pop() = 0;
  virtual void push(T const&) = 0;
};