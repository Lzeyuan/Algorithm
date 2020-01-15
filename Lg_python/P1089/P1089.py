str1 = []

unknow = 0

sum1 = 0

sign = 1

temp = []

time = 1

str1 = input()

flag = 1

lenth = len(str1)

def output(t):
    time = 1
    add = 0
    for i in range(len(t)):
        a = int(t.pop())
        add += a * time
        time *= 10
    return add

for i in range(lenth):
    if str1[i].isdigit():
        temp.append(str1[i])
        continue
    
    if str1[i] == '-':
        sum1 += output(temp) * sign * flag
        temp.clear()
        flag = -1
        continue
    
    if str1[i].isalpha():
        char = str1[i]
        if not temp:
            unknow += sign * 1 * flag
        else:
            unknow += sign * output(temp) * flag
        temp.clear()
        flag = 1
        continue
        
    if str1[i] == '=' :
        sum1 += output(temp) * sign * flag
        sign = -1
        temp.clear()
        flag = 1
        continue

    if str1[i] == '+':
        sum1 += output(temp) * sign * flag
        temp.clear()
        flag = 1
        continue
sum1 += output(temp) * sign * flag
'''if sum1 == 0:
    print('a={0:.3f}'.format(sum1/(-1*unknow) * -1))
else:'''
result = sum1/(-1*unknow)
print('{0}={1:.3f}'.format(char,result if result != 0 else abs(result)))
