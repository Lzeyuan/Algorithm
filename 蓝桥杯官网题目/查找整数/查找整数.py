n = int(input())

a = list(map(int, input().split()))

key = int(input())

try:
    t = a.index(key) + 1
except:
    print("-1")
else:
    print(t)
print("asdasddsasda")
