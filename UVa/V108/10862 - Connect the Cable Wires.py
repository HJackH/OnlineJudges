a = [0] * 2500
a[1] = 1
a[2] = 3

for i in range(3, 2002):
    a[i] = a[i - 1] * 3 - a[i - 2]

while True:
    n = int(input())
    if n == 0:
        break
    print(a[n])
