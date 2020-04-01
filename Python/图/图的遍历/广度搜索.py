
# 队列初始化
que = []
head = 1
tail = 1

n,m = map(int, input().split()) # n个点，m条边
map1 = [[float("inf") if i != j else 0 for i in range(m + 1)] for j in range(n + 1)]
book = [0 for i in range(100) ]

for i in range(m):
    a, b = map(int, input().split())
    map1[a][b] = 1
    map1[b][a] = 1

# 入队
que = [float("inf")]
que.append(1)
tail += 1
book[1] = 1

while(head < tail and tail <= n):
    cur = que[head]
    for i in range(1, n+1):
        if map1[cur][i] == 1 and book[i] == 0:
            que.append(i)
            tail += 1
            book[i] = 1
        if tail > n:
            break
    head += 1
    
for i in range(1, tail):
    print(que[i], end=" ")
print()
        
    
