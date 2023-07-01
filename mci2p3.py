start, dir = input().split()

if dir == "ns":
    dir = 1
else:
    dir = -1

conv = {}
conv[start] = dir

n = int(input())
for i in range(n):
    u, v = input().split()
    conv[v] = -conv[u]

ns = 0
ew = 0

for i in conv:
    if conv[i] > 0:
        ns += 1
    else:
        ew += 1
print(ns, ew)