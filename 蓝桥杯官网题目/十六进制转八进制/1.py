n = int(input())

a = list( input() for i in range(n) )

for i in range(n):
    a[i] = int(a[i],16)

for i in range(n):
    print('%o' % a[i])
    
    
    
