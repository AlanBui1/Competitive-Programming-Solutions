n, m = map(int, input().split())
a = [int(i) for i in input().split()]

for i in range(m):
    ind = a.index(min(a))
    print(a[ind])
    a[ind] += 1