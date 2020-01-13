number = input()
number2 = ''
if number[0] == '-':
    print('-',end='')
    for i in range(len(number)-1,0,-1):
        number2 += number[i]
    print(int(number2))
else:
    for i in range(len(number) - 1,-1,-1):
        number2 += number[i]
    print(int(number2))
