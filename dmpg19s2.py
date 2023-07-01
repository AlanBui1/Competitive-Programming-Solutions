decrypter = [[int(i) for i in input()]for k in range(10)]
d = [int(i) for i in input()]
e = [-1 for i in d]
n = len(d)
e[0] = d[0]

for i in range(1, n):
    e[i]= decrypter[e[i-1]].index(d[i])

print(*e, sep="")