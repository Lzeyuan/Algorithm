#!/usr/bin/env python

n = int(input())

a = list(map(int,input().split()))

a = list(set(a))

a.sort()

length = len(a)

print(length)

for i in range(len(a)):
    print(a[i], end = ' ')
