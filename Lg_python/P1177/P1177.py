n = int(input())

num = [int(i) for i in input().split()]

num.sort();

for i in range(n):
    print(num[i], end = ' ')
