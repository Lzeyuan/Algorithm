n = int(input())

for i in range(1, 10):
    for j in range(10):
        for k in range(10):
            if i*2 + j*2 + k == n:
                print(i+j*10+k*100+j*1000+i*10000)

for i in range(1, 10):
    for j in range(10):
        for k in range(10):
            if i*2 + j*2 + k*2 == n:
                print(i+j*10+k*100+k*1000+j*10000+i*100000)
