#n点，m边
n,m = map(int, input().split())

e = [[float("inf") if i != j else 0 for i in range(n+1)] for j in range(n+1)]

for i in range(m):
    a, b, c = map(int, input().split())
    e[a][b] = c

for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            if e[i][j] > e[i][k] + e[k][j]:
                e[i][j] = e[i][k] + e[k][j]
                print('k=',k,'i=',i,'j=',j,'=============')
                for a in range(1,n+1):
                    for b in range(1,n+1):
                        print('%8.0f' %e[a][b], end = '')
                    print()
                
