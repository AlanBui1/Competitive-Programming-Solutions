from math import sin, radians

n = int(input())
h= 0
for i in range(n):
    s, x, t = map(float, input().split())

    h += t*s*sin(radians(x))

print(round((2*9.8*h)**0.5))