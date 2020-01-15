### 1.模拟C语言while(scanf(“%d”,&a))：

```python
for i in range(1,m+1): 
    t1, t2, t3 = map(int,input().split())
	e[t1][t2] = t3 

num = [int(i) for i in input().split()]
```



### 2.模拟C语言a:

```python
e = [ [0 for i in range(n+1)]  for j in range(n+1)]
```

**而且可以动态创建数组。**

 

### 3.模拟C语言格式化输出：

```python
 print( "{0:10.0f}".format( e[i][j] ), end = '' )
```



### 4.模拟C语言循环输出：

```c
//C语言：
for( i = 0; i < 10 ; i++ )
	Printf("%d",a[i]);
```
```python
#python：
for j in range(1,n+1):
  print( "{0:.0f}".format( int( e[j] ) ), end = '' )
```



### 5.a = list(set(a)) 可以去掉多余变量，但是会改变次序

 

### 6.读入n行数据：

```python
n = int( input().split() )
interview = [list( map( int , input().split() ) ) for i in range(n)]
```

![image-20191216182533700](/Data/image-20191216182533700.png)

 

### 7.倒序输出：

``` python
#正序输出：
for i in range( 0, len(interview) ):
	print(interview[i][0],interview[i][1])

#倒序输出：
for i in range( len(interview), 0, -1):
	print(interview[i][0],interview[i][1])
```

 

### 8. 模拟C语言读入多组数据：

**C/C++:**

~~~c++
#include <iostream>

while ( std::cin >> a >> b )
    std::cout << a+b;
~~~

**python:**

```python
import sys

while True:
    line = sys.stdin.readline()
  	if not line:
        break
        
a, b = (int(x) for x in line.split())

print(a + b)
```
