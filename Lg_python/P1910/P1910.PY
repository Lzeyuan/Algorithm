n, m, x = map(int, input().split())

f = [ [0 for j in range(1001)]  for i in range(1001)]

def ZeroOnePack(m,x):
    for i in range(n):
        t = list(map(int, input().split()))
        for j in range(m,t[1]-1,-1):
            for k in range(x,t[2]-1,-1):
                f[k][j] = max(f[k-t[2]][j-t[1]]+t[0],f[k][j])
                
    return f[x][m]
print(ZeroOnePack(m,x))
