import math
a, b, c = map(int, input().split())
x, y, z = map(int, input().split())

if math.floor(a**0.5) == math.floor(x**0.5) and math.floor(b**0.5) == math.floor(y**0.5) and math.floor(c**0.5) == math.floor(z**0.5):
    print("Dull")
else:
    print("Colourful")