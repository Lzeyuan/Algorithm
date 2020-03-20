n,k = map(int,input().split())

e = list( int(i) for i in input().split())      #读入E[i]的权
e.insert(0,0)
      
w = list( int(i) for i in input().split())      #读入W[i]的权
w.insert(0,0)

t = w[:]

for i in range( 1, len(t)):     #列表d冒泡排序
    for j in range( 1, len(t) - i):
        if t[j] > t[j+1]:
            temp = t[j]
            t[j] = t[j+1]
            t[j+1] = temp
            
d = list()

for i in range(1, len(t)):      #给d加入序号
    d.insert(-1, [i,t[i]])
d.pop()
d.insert( 0, [0,0])

print(d)

for i in range( 1, len(d)):     #额外加权
    d[i][1] += e[(i-1) % 10 + 1]

for i in range( 1, len(d)):     #列表d冒泡排序
    for j in range( 1, len(d) - i):
        if d[j][1] > d[j+1][1]:
            d[j], d[j+1] = d[j+1], d[j]

d.reverse()

for i in range( 0, k):
    print( d[i][0], end=' ' )
