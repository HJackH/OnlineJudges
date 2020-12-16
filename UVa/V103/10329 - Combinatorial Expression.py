import math

# if python version < 3.8
def comb(n, r):
    return (math.factorial(n) // math.factorial(r)) // math.factorial(n - r)

try:
    while True:
        n, m = map(int, input().split(' '))
        up = 1
        down = 1
        for i in range(0, n):
            a, b = map(int, input().split(' '))
            up *= math.comb(a, b)
        for i in range(0, m):
            a, b = map(int, input().split(' '))
            down *= math.comb(a, b)
        if up % down == 0:
            ans = up // down
            if len(str(ans)) < 101:
                print(ans)
            else:
                print(-1)
        else:
            print(0)
except EOFError:
    pass