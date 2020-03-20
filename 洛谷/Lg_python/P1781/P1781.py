n = int(input())

president = list([0])

for i in range(1,n+1):
    poet = int(input())
    president.append([i,poet])

for i in range(1,n+1):
    for j in range(1,n - i + 1):
        if president[j][1] > president[j+1][1]:
            temp = list()
            temp = president[j]
            president[j] = president[j+1]
            president[j+1] = temp

print(president[n][0])
print(president[n][1])
