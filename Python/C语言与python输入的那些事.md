# 1.模拟C语言a创建固定数组:

**C/C++**

```c++
int a[n][m]
```

**Python**

```python
e = [ [0 for i in range(n+1)]  for j in range(n+1)]
```



# 2.模拟C语言逐个输入

输入n行，m列

**C/C++**

``` c++
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
	    cin << a[i][j];        
    }
}
```



**Python**

```python
a = list()
while len(a) < n*m:
    t = input().split()
    a.extend(t)

b = list()
for i in range(n):
    t = a[i:i+m]
    a
```



为什么不用

``` python
a = [list(map(int, input().split())) for i in range(n)]
```

​	原因看下图，矩阵X,Y，并没有明确说明是x行，y列，只能自己重新规定n行，m列,因此，输入时则需要逐个输入。

![2](F:\Code\Python\图片\2.png)