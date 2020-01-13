#!/usr/bin/env python

import sys   
sys.setrecursionlimit(100000)

#右下左上
step = [[ 0, 1],
        [ 1, 0],
        [ 0, -1],
        [ -1, 0]]

#Dfs
def Dfs( ship, row, col, flag):
    global area2
    global c
    global r
    global book
    global rx, cy
    
    if not flag :
        return
    
    for i in range(4):
        x = row + step[i][0]
        y = col + step[i][1]
        
        #判断是否越界
        if x < 0 or y < 0 or x > r - 1 or y > c - 1:
            continue
        
        #判断是否已经遍历
        if book[x][y] == 1:
            continue
            
        #记录面积
        if ship[x][y] == '#':
            
            #判断矩形
            if x > rx - 1 or y > cy - 1 :
                flag = False
                
            book[x][y] = 1
            area2 += 1
            Dfs( ship, x, y, flag)
            
    
            
'=================mian================'

#输入行列数
r, c = map( float, input().split() )

r = int(r)
c = int(c)

#初始化地图
ship = [ [ i for i in input() ] for j in range(r) ]
book = [ [ 0 for i in range(c) ] for j in range(r) ]
flag = True
ans = 0

#开始判断
for row in range(r):
    for col in range(c):
        if ship[row][col] == '.' or book[row][col] == 1:
            continue
        
        else:
            #第一次计算面积
            cy = col
            rx = row
            
            while cy < c and ship[row][cy] == '#':
                cy += 1
            while rx < r and ship[rx][col] == '#':
                rx += 1

            area2 = 1

            book[row][col] = 1
            Dfs( ship, row, col, flag)
            
            rx -= row
            cy -= col
            
            area1 = rx * cy
            
            if area1 != area2:
                flag = False
                break
            ans += 1
            
    if not flag :
        break

#输出答案
if flag == True:
    print('There are', ans ,'ships.')
else:
    print( 'Bad placement.')

