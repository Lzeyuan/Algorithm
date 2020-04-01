# 最大公因数
def gcd(a, b):
    return a if b == 0 else gcd(b, a%b)

print(gcd(12,15))
print(gcd(12,0))

# 扩张欧几里得算法
def extgcd(a, b, x, y):
    d = a
    if b != 0:
        d = extgcd(b, a%b,y,x)
        y -= (a/b)*x
    else:
        x = 1
        y = 0
    return d

x = y = 0
extgcd(4,11,x,y)
