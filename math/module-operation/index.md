# 取模运算

取模在编程中很常见，下面主要是针对取模做了一些总结。

## 优先级

取模运算在很多的编程语言中，取模的优先级和乘除一样，结合性也一样，也就是说$a * b \% p = (a * b) \% p \neq a * (b \% p)$

为了下面的证明方便，我们假设$a = k_1p+r_1$，$b=k_2p+r_2$

注意：$(a \% p) * (b \% p) \neq a \% p * b \% p$

证明如下：

$$
\begin{aligned}
(a \% p) * (b \% p) &= r_1 * r_2 \\
a \% p * b \% p &= r_1 * (k_2 p + r_2) \% p \\
&= (r_1 k_2 p + r_1 r_2) \% p= (r_1 r_2) \% p
\end{aligned}
$$

## 运算法则

1. 法则：$(a+b)\%p=(a\%p+b\%p)\%p$

证明：

$$
\begin{aligned}
lhs &= (r_1 + r_2) \%p \\
rhs &= ((k_1+k_2)p + (r_1 + r_2)) \% p \\
&= (r_1 + r_2) \% p
\end{aligned}
$$

2. 法则：$(a-b)\%p=(a\%p-b\%p)\%p$

证明：

$$
\begin{aligned}
lhs &= (r_1 - r_2) \%p \\
rhs &= ((k_1-k_2)p + (r_1 - r_2)) \% p \\
&= (r_1 - r_2) \% p
\end{aligned}
$$

3. 法则：$(a \times b)\%p=((a\%p) \times (b\%p))\%p = (a\%p \times b\%p) \%p$

证明：

$$
\begin{aligned}
(a \times b)\%p &= (k_1k_2p^2+(k_1r_2+k_2r_1)p+r_1r_2) \% p \\
&= (r_1r_2) \% p \\
((a\%p) \times (b\%p))\%p &= (r_1 r_2) \%p \\
(a\%p \times b\%p) \%p &= (r_1 * b \% p) \% p  \\
&= (r_1 * (k_2 p + r_2) \% p) \% p \\
&= ((r_1 k_2 p + r_1r_2) \%p) \%p \\
&= (r_1 k_2 p + r_1r_2) \%p \\
&= (r_1r_2) \%p
\end{aligned}
$$

4. 法则：$a^b \% p = (a\%p)^b \% p$

证明：

$$
\begin{aligned}
lhs &= (k_1p+r_1)^b \% p \\
&= ( C_b^0 r_1^b + ...+ C_b^b(k_1 p)^b ) \% p \\
&= r_1^b \% p \\
rhs &= r_1^b \% p
\end{aligned}
$$


**推论**：

1. 结合律

$$
((a + b) \% p + c) \% p = (a + (b + c) \% p) \% p \\
((a * b) \% p * c) \% p = (a * (b * c) \% p) \% p
$$

证明如下：

$$
\begin{aligned}
&((a + b) \% p + c) \% p \\
= &((a \% p + b \% p) \% p + c) \% p \\
= &((a \% p + b \% p) \% p \% p + c \% p) \% p \\
= &((a \% p + b \% p) \% p + c \% p) \% p \\
= &(a \% p + b \% p + c ) \% p \\
= &(a \% p \% p + b \% p \% p + c \% p) \% p \\
= &(a \% p + b \% p + c \% p) \% p \\
= &(a \% p + b \% p \% p + c \% p \% p) \% p \\
= &(a + b \% p + c \% p) \% p \\
= &(a \% p + (b \% p + c \% p) \% p) \% p \\
= &(a \% p + (b \% p + c \% p) \% p \% p) \% p \\
= &(a + (b \% p + c \% p) \% p) \% p \\
= &(a + (b + c) \% p) \% p
\end{aligned}
$$

$$
\begin{aligned}
&((a * b) \% p * c) \% p \\
= &(((a \% p) * (b \% p)) \% p * c) \% p \\
= &(((a \% p) * (b \% p)) \% p \% p * (c \% p)) \% p \\
= &(((a \% p) * (b \% p)) \% p * (c \% p)) \% p \\
= &(((a \% p) * (b \% p)) * c) \% p \\
= &((a \% p \% p) * (b \% p \% p) * (c \% p)) \% p \\
= &((a \% p) * (b \% p) * (c \% p)) \% p \\
= &((a \% p) * (b \% p \% p) * (c \% p \% p)) \% p \\
= &(a * (b \% p) * (c \% p)) \% p \\
= &((a \% p) * ((b \% p) * (c \% p)) \% p) \% p \\
= &(a \% p * ((b \% p) * (c \% p)) \% p \% p) \% p \\
= &(a * ((b \% p) * (c \% p)) \% p) \% p \\
= &(a * (b * c) \% p) \% p
\end{aligned}
$$

2. 交换律

$$
(a + b) \% p = (b + a) \% p \\
(a * b) \% p = (b * a) \% p
$$

3. 分配律
$$
((a + b) \% p * c) \% p = ((a * c) \% p + (b * c) \% p) \% p
$$

证明如下：

$$
\begin{aligned}
&((a + b) \% p * c) \% p \\
= &(a \% p + b \% p) \% p * c) \% p \\
= &((a \% p + b \% p) \% p \% p) * (c \% p)) \% p \\
= &(a \% p + b \% p) \% p * (c \% p)) \% p \\
= &((a \% p + b \% p) * c) \% p \\
= &(a \% p * c + b \% p * c) \% p \\
= &(a \% p * c \% p + b \% p * c \% p) \% p \\
= &((a \% p * c \% p) \% p + (b \% p * c \% p) \% p) \% p \\
= &((a * c) \% p + (b * c) \% p) \% p
\end{aligned}
$$

## 重要性质

同余式：正整数a，b对p取模，它们的余数相同，记做$a \equiv b (\% p)$。

- 若$a \equiv b (\% p)$，则$\forall c, (a + c) (b + c)(\% p)$
- 若$a \equiv b (\% p)$，则$\forall c, (a * c) \equiv (b * c) (\% p)$
- 若$a \equiv b (\% p)$，则$\forall c, (a + c) \equiv (b + c) (\% p)$
- 若$a \equiv b (\% p)，c \equiv d (\% p)$，则 $(a + c) \equiv (b + d) (\% p)，(a - c) \equiv (b - d) (\% p)，(a * c) \equiv (b * d) (\% p)$
