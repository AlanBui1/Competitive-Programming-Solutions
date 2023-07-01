n, m, k = map(int, input().split())

x = {}
y = {}
ones = []

for i in range(k):
    a, b = map(int, input().split())

    if a not in x:
        x[a] = 0
    if b not in y:
        y[b] = 0
    
    x[a] += 1
    y[b] += 1
    ones.append([a, b])

print(len(ones))
for a, b in ones:
    print(a, b)