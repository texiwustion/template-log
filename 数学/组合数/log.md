# G - foreverlasting and fried-chicken 

https://vjudge.net/contest/724460#problem/G

公式使用了 C(r,4) ...

```cpp
Z x = C(r.x, 4);
Z d1 = deg[i] - 4, d2 = deg[j] - 4;
if (g[i][j]) d1 -= 1, d2 -= 1;
Z y = C(d1.x, 2) + C(d2.x, 2);
```

# 