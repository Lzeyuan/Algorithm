#!/usr/bin/env python

#左上右下
step = [ [ 0, -1 ],
         [ 1, 0 ],
         [ 0, 1 ],
         [ -1, 0 ] ]

#DFS
def Dfs( a, row, col ):
    global r
    global c
    global book
    #print(book)
    for i in range(4):
        x = row + step[i][0]
        y = col + step[i][1]

        #判断是否越界
        if x > r - 1 or y >  c - 1 or x < 0 or y < 0 :
            continue
        
        #判断是否走过
        if book[x][y] == 1:
            continue

        #记录
        if a[x][y] > '0' :
            book[x][y] = 1
            Dfs(a , x ,y )

    

'=============主函数==========='

#读入行列数
r,c = map( int, input().split() )

#初始化矩阵
a = list()
time = 0
ans = 0

#读入矩阵
for row in range( 1, r + 1 ):
    cb = input()
    b = list()
    for each in cb:
        '''temp = int( each )
        b.append( temp )'''
        b.append(each)
    a.append(b)

#记录是否走过
book = [ [ 0 for i in range( c ) ] for j in range( r ) ]

#开始查找细胞
for row in range( r ):
     for col in range( c ):
        if a[row][col] == '0' or book[row][col] == 1:
            continue
        else:
            Dfs( a, row, col )
            book[row][col] = 1
            #print(row,col)
            ans += 1

#输出答案
print(ans)

