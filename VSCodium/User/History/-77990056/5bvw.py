def Func(num):
    n = 3
    a = [0] * 4
    for i in range(1, 4):
        a[i] += a[i & (i - 1)] + 1
    
    for i in a:
        print(i, end=' ')
    print()


Func(69)