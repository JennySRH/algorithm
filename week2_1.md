## Greedy Algorithms

### 贪心选择性质



### 最优子结构性质



### Introduction

局部最优选择，i.e. 单源最短路经问题，最小生成树问题等



### 1. Activity Selection Problems 活动选择问题 



![1551831141347](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1551831141347.png)![1551831173191](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1551831173191.png)

把活动按照某种方式排序，然后根据兼容性情况选取活动。

![1551831500023](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1551831500023.png)

![1551831551130](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1551831551130.png)



#### Greedy algorithm. 

Consider jobs in increasing order of finish time. Take each job provided it's compatible with the ones already taken.

```c++
Sort activities by finish times so that f1 <= f2 <= ... <= fn
A = Ф
for j = 1 to n {
if (activity j compatible with A) A = A ∪ {j}
}
return A
```

排序需要 $O(nlogn)$，循环需要 $O(n)$ ，所以需要 $O(nlogn)$ 

#### proof

假设最优算法是$S^*$，贪心算法 是 S，需要证明 $f(S^* )$ <= f(S)

一般用反证法， 即证明 $f(S^* )$ > f(S) 是错的

$S^* -> S^1 -> S^2 -> ... -> S$

$S^*$ 最后转为贪心解  S

![1551832423165](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1551832423165.png)

### 2. Interval Partitioning  Problem

find minimum number of classrooms to schedule all lectures so that no two occur at the same time in the same room.

![1551832791146](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1551832791146.png)

#### Greedy algorithm. 

Consider lectures in increasing order of start time: assign lecture to any compatible classroom.

```c++
Sort intervals by starting time so that s1 ≤ s2 ≤ ... ≤ sn.
d ← 0
for j = 1 to n {
    if (lecture j is compatible with some classroom k)
    	schedule lecture j in classroom k
    else
    	allocate a new classroom d + 1
    	schedule lecture j in classroom d + 1
    	d ← d + 1
}
```

Implementation. $O(n log n)$.
For each classroom k, maintain the finish time of the last job added.
Keep the classrooms in a priority queue.

#### proof

![1551833961535](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1551833961535.png)



### 3. Fraction Knapsack Problem

![1551834470013](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1551834470013.png)

物品可分割

![1551834873197](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1551834873197.png)

![1551834902472](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1551834902472.png)

![1551834933988](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1551834933988.png)



