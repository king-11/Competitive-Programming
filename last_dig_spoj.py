import math as maths

n = int(input())
for x in range(n):
    a, b = map(int, input().split())
    a = a % 10
    if b == 0:
        print(1)
    elif a in (0, 5, 6, 1):
        print(a)
    elif a in (4, 9):
        if b & 1:
            print(a)
        else:
            a = a*a
            a = a % 10
            print(a)
    else:
        b %= 4
        if b == 0:
            b = 4
        a = int(maths.pow(a, b) % 10)
        print(a)
