# n点，m边
n,m = map(int, input().split())

#图
e = [ [float("inf") if i != j else 0 for i in range(n + 1)] for j in range(n+1) ]
book = [ 0 for i in range(n + 1)]


def Dfs(cur, s):
    global n
    print(cur, end=" ")
    s += 1
    if s == n:
        return
    for i in range(1,n+1):
        if e[cur][i] == 1 and book[i] == 0:
            book[i] = 1
            Dfs(i, s)
    return
for i in range(1,m+1):
    a, b = map(int, input().split())
    e[a][b] = 1
    e[b][a] = 1
    
book[1] = 1
Dfs(1,0)
