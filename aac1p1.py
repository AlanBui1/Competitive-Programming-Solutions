import math

s, r = map(int, input().split())
square = s*s
circle = math.pi*(r**2)

if square>circle:
    print("SQUARE")
else:
    print("CIRCLE")