# 矩阵的压缩

数学上的矩阵在编程中类似于二维数组，二维数组可以视为其元素是定长的数组。

- 压缩存储∶指为多个值相同的元素只分配一个存储空间，对零元素不分配存储空间。其目的是为了节省存储空间。
- 特殊矩阵∶指具有许多相同矩阵元素或零元素，并且这些相同矩阵元素或零元素的分布有一定规律性的矩阵。常见的特殊矩阵有对称矩阵、上（下）三角矩阵、对角矩阵等。
- 特殊矩阵的压缩存储方法∶找出特殊矩阵中值相同的矩阵元素的分布规律，把那些呈现规律性分布的、值相同的多个矩阵元素压缩存储到一个存储空间中。

### 对称矩阵

特点：

1. 矩阵是方阵
2. $a_{i,j} = a_{j, i}$

$$
\begin{bmatrix}
a_{1,1} & a_{1,2} & \cdots & a_{1,n} \\
a_{2,1} & a_{2,2} & \cdots & a_{2,n} \\
\vdots & \vdots & \ddots & \vdots \\
a_{n,1} & a_{n,2} & \cdots & a_{n,n} \\
\end{bmatrix}
$$

我们可以将矩阵分成三部分

$$
\begin{cases}
i > j, & \text{下三角区} \\
i = j, & \text{主对角线} \\
i < j, & \text{上三角区}
\end{cases}
$$

由$a_{i,j} = a_{j,i}$可知，我们只需要存储下三角区（或上三角区）和主对角线上的元素。

$$
\begin{bmatrix}
a_{1,1} & & & \\
a_{2,1} & a_{2,2} & & \\
\vdots & \vdots & \ddots & \\
a_{n,1} & a_{n,2} & \cdots & a_{n,n} \\
\end{bmatrix}
$$

在具体的实现中，我们使用一位数组来存储矩阵，并使用`int f(int i, int j)`将矩阵的下标$i,j$映射到其存储数组的实际下标。

$$
f(i, j) = 
\begin{cases}
\sum_{i = 1}^{i-1} + j - 1 = \cfrac{i(i-1)}{2} + j - 1, & i \geq j \\
f(j,i) & i < j
\end{cases}
$$

## 下三角矩阵

特点：$a_{i,j} = 0, i > j$

$$
\begin{bmatrix}
a_{1,1} & \cdots & \cdots & 0 \\
a_{2,1} & a_{2,2} & & \vdots \\
\vdots & \vdots & \ddots & \vdots \\
a_{m,1} & a_{m,2} & \cdots & a_{m,n} \\
\end{bmatrix}
$$

由上面对称矩阵的存储，我们可以知道

$$
f(i, j) = 
\begin{cases}
\sum_{i = 1}^{i-1} + j - 1 = \cfrac{i(i-1)}{2} + j - 1, & i \geq j \\
0 & i < j
\end{cases}
$$

## 上三角矩阵

特点：$a_{i,j} = 0, i < j$

$$
\begin{bmatrix}
a_{1,1} & a_{1,2} & \cdots & a_{1,n} \\
\vdots & a_{2,2} & \cdots & a_{2,n} \\
\vdots & & \ddots & \vdots \\
0 & \cdots & \cdots & a_{m,n} \\
\end{bmatrix}
$$

$$
f(i, j) = 
\begin{cases}
\left[ n + (n-1) + \cdots + (n - i + 2) \right] + (j - i + 1) - 1 = \cfrac{(i-1)(2n-i+2)}{2} + j - i, & i \leq j \\
0 & i < j
\end{cases}
$$

## 三对角矩阵

也称为带状矩阵

特点：$a_{i, j} = 0, |i - j| < 1$

$$
\begin{bmatrix}
a_{1,1} & a_{1,2} & \cdots & \cdots & \cdots & 0 \\
a_{2,1} & a_{2,2} & a_{2,3} & & & \vdots \\
\vdots & a_{3,2} & a_{3,3} & a_{3,4} & & \vdots \\
\vdots & & \ddots & \ddots & \ddots & \vdots \\
\vdots & & & a_{n-1, n-2} & a_{n-1, n-1} & a_{n-1, n} \\
0 & \cdots & \cdots & \cdots & a_{n,n-1} & a_{n,n} \\
\end{bmatrix}
$$

## 稀疏矩阵

矩阵中非零元素的个数$t$，相对矩阵元素的个数$s$来说非常少，即$s>>t$的矩阵称为稀疏矩阵。

### 三元顺序表

|$i$|$j$|$a_{i,j}$|
|:-:|:-:|:-:|
|||

三元组顺序表每次提取指定元素都需要遍历整个数组，运行效率很低。

[三元组顺序表](http://data.biancheng.net/view/184.html)

### 行逻辑链接的顺序表

它可以看作是三元组顺序表的升级版，即在三元组顺序表的基础上改善了提取数据的效率。

行逻辑链接的顺序表和三元组顺序表的实现过程类似，它们存储矩阵的过程完全相同，都是将矩阵中非 0 元素的三元组（行标、列标和元素值）存储在一维数组中。但为了提高提取数据的效率，前者在存储矩阵时比后者多使用了一个数组，专门记录矩阵中每行第一个非 0 元素在一维数组中的位置。

[行逻辑链接的顺序表（压缩存储稀疏矩阵）详解](http://data.biancheng.net/view/185.html)

### 十字链表法

对于压缩存储稀疏矩阵，无论是使用三元组顺序表，还是使用行逻辑链接的顺序表，归根结底是使用数组存储稀疏矩阵。介于数组 "不利于插入和删除数据" 的特点，以上两种压缩存储方式都不适合解决类似 "向矩阵中添加或删除非 0 元素" 的问题。

[十字链表法](http://data.biancheng.net/view/186.html)