#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iterator>
using namespace std;
struct node {
  int st, ed;
  //作者自己手撸了一个低配版本（顺序查找的）的map，list 与 ch 的功能，相当于 map<char, noed *>
  int cnt;//用于记录list和ch的长度
  node *ch[50];//children
  char list[50];
  
  int tot;//用于记录当前前缀的个数
};
char list[10000000],//单词大集合，缓冲区
     s[20000], //用于读入时，存储一个单词
     re; //用于读入时，储存一个字符
node *T = new(node), *tnode;
int n, //单词个数
    cmq, //最终的答案，前缀个数 * 前缀长度
    len, //用于读入时候，存储一个单词的长度
    size,//缓冲区list的大小
    tmp;
//这个函数应该是一个初始化
void clear(node *p) {
  p -> st = p -> ed = size;
  p -> cnt = 0;
  p -> tot = 0;
}

// 返回值 <= min{p->ed - p->st, len - st}
int same(node *p, int st) {
  int i;
  for(i = 0; p -> st + i < p -> ed && st + i < len && s[st + i] == list[p -> st + i]; i++);
  return i;
}

//感觉这个应该是拆分的函数
void diliver(node *&p, int len) {
  node *t = new(node);
  t -> tot = p -> tot;
  t -> st = p -> st;
  t -> ed = t -> st + len;
  //在t中插入子节点
  t -> cnt = 1;
  t -> list[0] = list[t -> ed];
  t -> ch[0] = p;
  p -> st = t -> ed;
  p = t;
}
//查找以ch开头的孩子的索引
int find(node *p, char ch) {
  for(int i = 0; i < p -> cnt; i++)
    if(p -> list[i] == ch)
      return i;
  return -1;
}
// p 是当前节点，st表示当前单词s的开始下标
void insert(node *&p, int st) {
  int ll = same(p, st);//当前节点 与 单词[s, len)的共同前缀长度
  //由于ll <= p->ed - p->st，所以只需要判断ll < p->ed - p->st <=> !(ll != p->ed - p->st)
  if(ll == p -> ed - p -> st) {
    p -> tot++;//增强当前节点的公共前缀的个数
    st = st + ll;
  } else /*ll < p ->ed - p->st*/{
    diliver(p ,ll);
    p -> tot++;
    st = st + ll;
  }
  if(st == len)//这个单词已经插入完成
    return;
  else {
    tmp = find(p, s[st]);
    if(tmp != -1)
      insert(p -> ch[tmp], st);//递归插入
    else {
      tnode = new(node);
      p -> ch[p -> cnt] = tnode;
      p -> list[p -> cnt] = s[st];
      p -> cnt++;
      clear(tnode);
      //插入剩余的字母到缓冲区
      for(int i = st; i < len; i++)
        list[tnode -> ed++] = s[i];
      size = tnode -> ed;
      tnode -> tot = 1;
      return;
    }
  }
}
void dfs(node *p, int ll) {
  ll += p -> ed - p -> st;
  cmq = max(cmq, ll * p -> tot);
  for(int i = 0; i < p -> cnt; i++)
    dfs(p -> ch[i], ll);
}
int main() {
  clear(T);
  for(int i = 0; i < n; ++i) {
    re = getchar();
    len = 0;
    while(re != '\n') {
      s[len++] = re;
      re = getchar();
    }
    insert(T, 0);
  }
  dfs(T, 0);
  cout << cmq << endl;
  return 0;
}