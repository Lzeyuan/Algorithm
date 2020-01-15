#!/usr/bin/env python

#读入n
n = int( input() )

#记录占用的列
c = [ False for i in range( n + 1 ) ]

#记录被占用的右下斜线
rd = [ False for i in range( n + n + 1 ) ]

#记录被占用的左下斜线
ld = [ False for i in range( n + 2 ) ]

#记录答案
ans = list()
temp = list()
time = 3
key = 0

#因为不知道要判断多少次，因此使用递归
def check( step ):
    global n
    global r, c, ld, rd
    global temp, ans
    global time, key
    
    if step == 0:
        if time:
            ans.append(temp)
            print( temp )
            time -= 1
        key += 1
        return
        
    for i in range( 1, n + 1 ):
        if not c[i] and not ld[i + 1] and not rd[n - 1 + i]:
            c[i] = True
            ld[i + 1] = True
            rd[n - 1 + i] = True
            temp.append(i)
            check( step - 1 )
            c[i] = False
            ld[i + 1] = False
            rd[n - 1 + i] = False
            temp.pop()

#开始判断
check(n)
for i in range(3):
    print(ans[i])
print(key)
