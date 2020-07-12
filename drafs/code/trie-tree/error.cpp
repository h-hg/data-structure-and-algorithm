#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
//好像发现问题了，push_back，可能发生数组内存的转变，使得原先的引用失去了作用（原先的内存被释放）
struct S{
  map<int, int> m;
};
void error_usage() {
  vector<S> v;
  v.push_back(S());
  auto &s = v.front();
  v.push_back(S());//maybe size > capacity, the space storing elements is reallocated, the reference s is illegal
  s.m.insert({123,123});
}
void right_usage_1() {
  vector<S> v;
  v.push_back(S());
  auto &s = v.front();
  s.m.insert({123,123});
  v.push_back(S());
}
void right_usage_2() {
  
}
int main() {
  error_usage();
  return 0;
}