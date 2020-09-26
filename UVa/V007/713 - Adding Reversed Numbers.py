T = int(input())
while T > 0:
    a, b = input().split(' ')
    print(int(str(int(a[::-1]) + int(b[::-1]))[::-1]))
    T -= 1