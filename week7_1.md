### Breadth-first Traversal

【考试可能考，走迷宫——无权图最短路问题，熟练掌握】

![1554854947394](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1554854947394.png)



### Dijkstra

![1554855580800](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1554855580800.png)

用堆做加速

![1554855956937](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1554855956937.png)

【背过】

### Negative weight edges and cycles

### Bellman-Ford Algorithm

```c
RELAX(u, v, w)
1 if d[v] > d[u] + w(u, v)
2 then d[v] ← d[u] + w(u, v)

BELLMAN-FORD(G, w, s)
1 INITIALIZE-SINGLE-SOURCE(G, s)
2 for i ← 1 to |V[G]| - 1	// 迭代这么多次，每次都对所有的边松弛更新
3 do for each edge (u, v) ∈ E[G]
4 do RELAX(u, v, w)
5 for each edge (u, v) ∈ E[G]	// check negative cycles
6 do if d[v] > d[u] + w(u, v)	
7 then return FALSE
8 return TRUE
```

Complexity: O(VE)



### The Floyd-Warshall algorithm

![1554857885423](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1554857885423.png)

还是需要检测负环



### Difference constraints

![1554858800922](C:\Users\Administrator\Desktop\study\算法分析与设计\assets\1554858800922.png)