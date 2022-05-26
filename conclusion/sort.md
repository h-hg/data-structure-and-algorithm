# 排序

## argsort

```cpp
vector<int> argsort(vector<int> &arr) {
  auto idx = vector<int>(arr.size());
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&arr](int x, int y){
    return arr[x] < arr[y];
  });
  return idx;
}
```


## 归并排序

```cpp
void MergeSort(vector<int> &ar, vector<int> &tmp, int left, int right) {
  
}
```

```cpp
template <typename T>
void MergeSort(T ar[],T temp[],int left,int right,bool (*prior)(T const&,T const&))
{
  if(left < right)
  {
    int mid = (left + right) / 2;
    MergeSort(ar,temp,left,mid,prior);//[left,mid]
    MergeSort(ar,temp,mid+1,right,prior);//[mid+1,right]
    //the follow steps is Merge, the function of temp array is that copy ar to temp, store the result in ar.
    for(int i = left;i <= mid;++i)
      temp[i] = ar[i];
    for(int i = mid+1;i <= right;++i)//倒置存入
      temp[mid + right-i + 1] = ar[i];
    for(int l = left,r = right,k = left;k <= right;++k)
      if(prior(temp[l],temp[r]))
        ar[k] = temp[l++];
      else
        ar[k] = temp[r--];
  }
}
```