import math
try:
    while True:
        n = int(input())
        m = int(input())
        a = map(int, input().split(' '))

        ans = math.factorial(n)
        for i in a:
            ans = ans // math.factorial(i)
        print(ans)
except:
    pass