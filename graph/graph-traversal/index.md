# 图的遍历

## 广度搜素

```
function bsf(root)
  queue q
  q.push(q)
  visit root
  while(q not empty)
    for i in [0, q.size())
      node <- q.front()
      q.pop()
      if node is visited
        continue
      visit node
      for child of node
        q.push(child)

```

## 深度搜素

```
funcition dfs(root)
  if root is visited
    return
  visit root
  for child of root
    dfs(root)
```

