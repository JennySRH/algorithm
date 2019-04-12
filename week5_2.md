### Minimum vertex cover of tree

可以用贪心，先找叶子节点，然后拿掉父亲

【动态规划】

ans\[i][0] 不选择节点i，以i为根的子树覆盖所需最少点数

ans\[i][1] 选择节点i，以i为根的子树覆盖所需最少点数

i是叶子，ans\[i][0]=0，ans\[i][1] =1
$$
ans[i][0]=\sum ans[j][1] \\
ans[i][1]= 1 + \sum min(ans[j][0],ans[j][1])\\
对于i所有的子节点j
$$
 【vertex cover】

### Traveling Salesman Problem(TSP)

$$
C(S,j)=min _{i \in S:i \neq j}C(S-\{j\},i)+d_{ij}
$$

![1553842685977](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1553842685977.png)



通过队列生成所有子集

集合的表示

i.e. n=5

S={} -> 00000 -> 0

S=(0) -> 00001 ->1

S=(1,3) -> 01010 ->10

判断i是否在集合S用与&操作，(1<<i)&S

S-{j}，(~(1<<j))&S



### 回溯法

【ppt】

#### 八皇后问题



![1553844363244](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1553844363244.png)