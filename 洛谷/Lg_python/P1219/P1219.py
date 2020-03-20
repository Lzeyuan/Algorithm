#!/usr/bin/env python

import time

#读入n
n = int( input() )

starttime = time.time()

#记录占用的列
c = [ False for i in range( n + 1 ) ]

#记录被占用的右下斜线
rd = [ False for i in range( n + n + 1 ) ]

#记录被占用的左下斜线
ld = [ False for i in range( n + n + 1 ) ]

#记录答案
ans = list([0])
times = 3
key = 0

#因为不知道要判断多少次，因此使用递归
def check( r ):
    global n
    global c, ld, rd
    global temp, ans
    global times, key
    
    if r == n + 1:
        if times:
            '''for i in range( 1, n + 1):
                print( ans[i], end = ' ')
            print()'''
            times -= 1
        key += 1
        return
        
    for i in range( 1, n + 1 ):
        if not c[i] and not ld[i + r] and not rd[n + r - i]:
            c[i] = True
            ld[i + r] = True
            rd[n + r - i] = True
            #ans.append( i )
            check( r + 1 )
            #ans.pop()
            c[i] = False
            ld[i + r] = False
            rd[n + r - i] = False
            
#开始判断
check(1)
print(key)

endtime = time.time()

dtime = endtime - starttime

print("程序运行时间：%.8s s" % dtime)

