### what are algorithms ?

well-defined finite set of rules that specifies a sequential series of elementary operations to be applied to some data called the input, producing after a finite amount of time some data called the output.

### characteristics of algorithms

1)input 2)output 3)definiteness 4)finiteness 5)effectiveness

【p.s. 习题课 解题报告（15%） 要有分析复杂度的情况】

### Design and analysis

1. what is the problem we have to solve?
2. does a solution exist?
3. can we find a solution, and is there more than one solution?
4. is the algorithm correct?
5. how efficient is the algorithm?

### e.g. Fibonacci sequence

Fibonacci sequence
$$
F_1 = F_2 = 1 , \\F_N = F _{n-1} + F_{N-2}
$$

```C++
int fib(int n) {
    return (n < 3? 1: fib(n-1)+fib(n-2));
}
```

有大量元素被重复计算

关注fib(int n) 函数被调用的次数，为$2F_n -1$

证明(数学归纳法)
$$
n=1,2\\
n>2,1+2(F_{n-1}-1)+2(F_{n-2}-1)\\=2(F_{n-1}+F_{n-2})-1=2F_n-1
$$

#### an iterative algorithm

```c++
int fib(int n) {
    int f_2;
    int f_1 = 1;
    int f_0 = 1;
    for(int i = 1;i < n;i ++) {
        f_2 = f_1 + f_0;
        f_0 = f_1;
        f_1 = f_2;
    }
    return f_0;
}
```

### e.g. matrix algorithm

![1551228338641](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1551228338641.png)

![1551228361715](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1551228361715.png)

【快速幂算法，复杂度$O(log_2^n)$】

#### A little more

General term formula
$$
F(n) = \frac{1}{\sqrt5}(\frac{1+\sqrt5}{2})^n-\frac{1}{\sqrt5}(\frac{1-\sqrt5}{2})^n
$$
n趋向于很大时，第二项趋于0

### measuring time

complexity

elementary operations

e.g. insertion sort

### asymptotic notations

Big-O: upper bound for a function f(n) 【worst case】

Big-Omega: lower bound for a function f(n)  	【best case】

Big-Theta: upper and lower bound for a function f(n) 只有上下界相同的情况才可以用 【average case】

【回去思考分析排序，重新练习一下~】



#### Stirling's approximation 



![img](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\4bed2e738bd4b31c19ead27a86d6277f9f2ff819.jpg)



### Practice

![1551231489973](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1551231489973.png)