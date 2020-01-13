#!/usr/bin/env/ python

n,k = map(int, input().split())

interview = list()
interview = [list( map( int , input().split() ) ) for i in range(n)]

interview.sort(key = lambda x: x[1])

local = int(k*1.5)

line = interview[n - local][1]

sum1 = 0
i = n - 1

while interview[i][1] >= line:
    sum1 += 1
    i -= 1

print(line,sum1)

interview = interview[n-sum1:]

interview.sort(key = lambda x: x[0])

for i in range( n-1, n-sum1, -1):
    print(interview[i][0],interview[i][1])
    
