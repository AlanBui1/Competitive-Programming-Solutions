import sys; input = sys.stdin.readline
from math import ceil

n, q= map(int, input().split())

psa = [0 for i in range(1414215)]

for i in range(n):
    x, y = map(int,input().split())

    psa[ceil(((x**2)+(y**2))**0.5)] += 1

for i in range(1, 1414215):
    psa[i] += psa[i-1]

for i in range(q):
    r= int(input())
    print(psa[r])