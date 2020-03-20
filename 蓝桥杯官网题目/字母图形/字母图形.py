n,m = map(int,input().split())

for i in range(n):
    
    for j in range(i,0,-1):
        print('%c' % chr(65+j), end = '')
        if i - j >= m - 1:
            break
        
    for j in range(i,m):
        print('%c' % chr(65+j-i), end = '')
    print()
