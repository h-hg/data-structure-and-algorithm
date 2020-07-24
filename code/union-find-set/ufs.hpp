#ifndef _UNION_FIND_SET_H
#define _UNION_FIND_SET_H
#include <map>
#include "ufsb.hpp"
using namespace std;

//union find set
template <typename T>
class UFS: protected UFSB{
protected:
  map<T, int> elem2id;
public:
  UFS(): UFSB(0) {}
  bool insert(T const &elem) {
    if(elem2id.count(elem))
      return false;
    int id = father.size();
    elem2id[elem] = id;
    father.push_back(id);
    return true;
  }
  bool isSameSet(T const &a, T const &b) {
    return UFSB::isSameSet(elem2id[a], elem2id[b]);
  }
  void merge(T const&a, T const&b) {
    UFSB::merge(elem2id[a], elem2id[b]);
  }
};

#endif