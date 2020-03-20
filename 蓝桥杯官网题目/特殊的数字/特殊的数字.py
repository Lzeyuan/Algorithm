for i in range(100,1000):
    a = pow(i%10, 3)
    b = pow(i//10%10, 3)
    c = pow(i//100%10, 3)
    if a+b+c == i:
        print(i)        
 
