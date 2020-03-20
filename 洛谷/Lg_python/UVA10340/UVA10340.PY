#!/usr/bin/env python

import sys

while True:
    line = sys.stdin.readline()
    if not line:
        break
    str1,str2 = map(list,line.split())
    for each in str2:
        if each == str1[0]:
            str1.pop(0)
        if len(str1) == 0:
            break
    if len(str1) == 0:
        print('Yes')
    else:
        print("No")
            

