MAXN = 1000 + 5
a = [0] * MAXN
a[1] = 2
a[2] = 5
a[3] = 13

for i in range(4, MAXN):
    a[i] = 2 * a[i - 1] + a[i - 2] + a[i - 3]

try:
    while True:
        n = int(input())
        print(a[n])
except:
    pass