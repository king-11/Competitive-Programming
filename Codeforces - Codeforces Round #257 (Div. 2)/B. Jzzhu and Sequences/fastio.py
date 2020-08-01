x, y = [int(z) for z in input().split()]
n = int(input())

n = (n % 6)
MOD = 1000000007
if n == 1:
    print(x % MOD)
elif n == 2:
    print(y % MOD)
elif n == 3:
    print((y-x) % MOD)
elif n == 4:
    print((-x) % MOD)
elif n == 5:
    print((-y) % MOD)
elif n == 0:
    print((x-y) % MOD)
