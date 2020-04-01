class note:
    def __init__(self,x,s):
        self.x = x
        self.s = s
    def make(self, x, s):
        self.x = x
        self.s = s
        
n, m, start, end = map(int, input().split())

#地图
e = [[float('inf') if i != j else 0 for i in range(n+1)] for j in range(n+1)]
#标记点
book = [0 for i in range(n+1)]

for i in range(m):
    a, b = map(int, input().split())
    e[a][b] = 1
    e[b][a] = 1

head = 1
tail = 1
que = [0]
que.append(note(start,0))
tail += 1
book[start] = 1

flag = False

while(head < tail):
    cur = que[head].x
    for i in range(1,n + 1):
        if e[cur][i] != float("inf") and book[i] == 0:
            que.append(note(i,que[head].s + 1))
            tail += 1
            book[i] = 1
            if que[tail - 1].x == end:
                flag = True
                break
    if flag == True:
        break
    head += 1

print(que[tail - 1].s)
                
    
