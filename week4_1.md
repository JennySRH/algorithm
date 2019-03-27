## Dynamic programming 动态规划

### Definition

Dynamic Programming (DP) is a method for solving complex problems by breaking them down into simpler subproblems. It is applicable to problems exhibiting the properties of overlapping subproblems and optimal substructure.
A problem is said to have overlapping subproblems if the problem can be broken down into subproblems which are reused several times or a recursive algorithm for the problem solves the same subproblem over and over rather than always generating new subproblems.
A problem is said to have optimal substructure if an optimal solution can be constructed efficiently from optimal solutions of its subproblems.

###Approaches

####top-down

direct fall-out of the recursive formulation of any problem.

memorize

####bottom-up

subproblems



### Development of DP algorithms

Characterize the structure of an optimal solution.

define subproblems(states).

write down the recurrence that relates subproblems.

compute the value of an optimal solution.

construct an optimal solution from computed information.



### Fibonacci Problem

#### Naive Recursive Function

```c++
int Fib(int n) {
	if (n==1 || n==2) return 1;
	return Fib(n-1)+Fib(n-2);
}
```

#### Top-down Approach

```c++
int Fib(int n) {
    if(n==1||n==2) return 1;
    if(F[n] is defined) return F[n];
    F[n] = Fib(n-1)+Fib(n-2);
    return F[n];
}
```

#### Bottom-up Approach

```c++
F[1] = F[2] = 1; 
for (int i = 3; i < N; i++) F[i] = F[i-1]+F[i-2];
```



### Jump Steps Problem

**problem** : frog can jump up 1, 3 or 4 steps in each move, calculate the number of different ways for the frog to achieve the n-th steps.
$$
D_n=D_{n-1}+D_{n-3}+D_{n-4} \\
D_0=1,D_n=0 \quad for \quad all \quad negative \quad n
$$
【写出状态转移方程是关键】

用到了子问题重叠的性质

【但是Fibonacci 和Jump steps problem 都不是最优化问题，只是为了说明子问题重叠的性质。】



### Weighted interval scheduling

![1553059191413](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1553059191413.png)

![1553059347564](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1553059347564.png)

![1553059367116](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1553059367116.png)

![1553059443681](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1553059443681.png)

![1553059632910](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1553059632910.png)

递归、递推转换

### Longest Common Subsequence

最长公共子序列问题

![1553059679912](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1553059679912.png)

![1553060031770](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1553060031770.png)

![1553060069168](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1553060069168.png)

### Longest Non-Decreasing Subsequence

![1553060133645](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1553060133645.png)

![1553060180466](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1553060180466.png)