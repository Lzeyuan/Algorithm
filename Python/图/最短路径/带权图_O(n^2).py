# !/usr/bin/env python3
#从 1 走到 n

min = float("inf")  #最小路径
start, end = map(int, input().split())
def Dfs(cur , dis):
    global min, end
    if dis > min:
        return
    if cur == end:
        min = dis if dis < min else min
        return
    for i in range(1,n+1):
        if e[cur][i] != float("inf") and book[i] == 0:
            book[i] = 1
            Dfs(i, dis + e[cur][i])
            book[i] = 0
    return
        

#n点，m边
n,m = map(int, input().split())

e = [[float("inf") if i != j else 0 for i in range(n+1)] for j in range(n+1)]

book = [0 for i in range(n+1)]

for i in range(m):
    a, b, c = map(int, input().split())
    e[a][b] = c

book[start] = start
Dfs(start, 0)
print(min)
